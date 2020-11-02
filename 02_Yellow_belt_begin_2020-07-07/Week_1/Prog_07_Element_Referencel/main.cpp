#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string operation_command, bus_stop;
    int stop_count = 0;
    is >> operation_command;
    if (operation_command == "NEW_BUS") {
        q.type = QueryType ::NewBus;
        is >> q.bus >> stop_count;
        q.stops.erase(q.stops.begin(), q.stops.end());
        for (int i = 0; i < stop_count; i++) {
           is >> bus_stop;
           q.stops.push_back(bus_stop);
        }
    } else if (operation_command == "BUSES_FOR_STOP") {
        q.type = QueryType ::BusesForStop;
        is >> q.stop;
    } else if (operation_command == "STOPS_FOR_BUS") {
        q.type = QueryType ::StopsForBus;
        is >> q.bus;
    } else if (operation_command == "ALL_BUSES") {
        q.type = QueryType ::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    bool has_stop = true;
    vector<string> buses_for_stops_;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (!r.has_stop) {
        os << "No stop" << endl;
    } else {
        for (const string& bus : r.buses_for_stops_) {
            os << bus << " ";
        }
        os << endl;
    }
    return os;
}

struct StopsForBusResponse {
    bool has_bus = true;
    vector <bool> has_interchange;
    vector<string> bus;
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (!r.has_bus) {
        os <<"No bus" << endl;
    } else {int i = 0;
        for (const string& stop : r.buses_to_stops.at(r.bus[i])) {
            os << "Stop " << stop << ": ";
            if (!r.has_interchange[i]) {
                os << "no interchange";
            } else {
                for (const string& other_bus : r.stops_to_buses.at(stop)) {
                    os << other_bus << " ";
                }
            }
            i++;
            os << endl;
        }
    }
    return os;
}

struct AllBusesResponse {
    bool has_buses_ = true;

    vector<string> all_buses;
    map <string, vector<string>> buses_for_stop_;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (!r.has_buses_) {
        os << "No buses" << endl;
    } else {
        for (const auto& bus_item : r.all_buses) {
            os << "Bus " << bus_item << ": ";
            for (const string& stop : r.buses_for_stop_.at(bus_item)) {
                os << stop << " ";
            }
            os << endl;
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {

        buses_to_stops[bus] = stops;
        for (const string& stop : stops) {

            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
           BusesForStopResponse busesForStopResponse;
        if (stops_to_buses.count(stop) == 0) {
            busesForStopResponse.has_stop = false;
        } else {
            for (const string& bus : stops_to_buses.at(stop)) {
                busesForStopResponse.buses_for_stops_.push_back(bus);
            }
        }
        return busesForStopResponse;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse stopsForBusResponse;
        if (buses_to_stops.count(bus) == 0) {
            stopsForBusResponse.has_bus = false;
        } else {
            for (const string &stop : buses_to_stops.at(bus)) {
                stopsForBusResponse.bus.push_back(bus);
                stopsForBusResponse.buses_to_stops[bus].push_back(stop);
                if (stops_to_buses.at(stop).size() == 1) {
                    stopsForBusResponse.has_interchange.push_back(false);
                } else {
                    stopsForBusResponse.has_interchange.push_back(true);
                    for (const string &other_bus : stops_to_buses.at(stop)) {
                        if (bus != other_bus) {
                            stopsForBusResponse.stops_to_buses[stop].push_back(other_bus);
                        }
                    }
                }
            }
        }
        return stopsForBusResponse;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse allBusesResponse;
        if (buses_to_stops.empty()) {
            allBusesResponse.has_buses_ = false;
        } else {
            for (const auto& bus_item : buses_to_stops) {
                allBusesResponse.all_buses.push_back(bus_item.first);           //cout << "Bus " << bus_item.first << ": ";
                for (const string& stop : bus_item.second) {
                    allBusesResponse.buses_for_stop_[bus_item.first].push_back(stop);
                    //cout << stop << " ";
                }
                //cout << endl;
            }
            allBusesResponse.has_buses_ = true;
        }
    return allBusesResponse;
    }

    private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}

