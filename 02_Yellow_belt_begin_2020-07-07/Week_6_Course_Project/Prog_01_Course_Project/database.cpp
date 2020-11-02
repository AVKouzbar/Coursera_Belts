#include "database.h"

#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std :: chrono;


void Database ::Add(const Date &date, const string &event) {
//  auto start_add = steady_clock::now();
    if (pointer[date].emplace(event).second)
        storage[date].push_back(event);
    }



//    auto it = storage.find(date);
//    if (it != storage.end()) {
//        auto events = it->second;
//        for (auto& ev : events) {
//            if (ev == event) {
//                return;
//            }
//        }
//    }

//      auto finish_add = steady_clock ::now();
//      cout << "Add: " << duration_cast<microseconds>(finish_add - start_add).count() << " mcs" << endl;


void Database::Print(ostream &os) const {
    for (const auto& item : storage) {
        for (const auto& event_to_print : item.second) {
            os << item.first << " " << event_to_print << endl;
        }
    }
}


string Database::Last(const Date &date) const {  // Нужно разобраться с ласт.
   // auto start_last = steady_clock::now();

    auto it = storage.lower_bound(date);
    if (it->first != date) {
        if (it == storage.begin()) {
            throw invalid_argument(date.ToString());
        }
        --it;
    } else if (it == storage.end()) {
        --it;
    }
    auto finish_last = steady_clock::now();
//    cout << "Last: " << duration_cast<microseconds>(finish_last - start_last).count() << " mcs" << endl;
    return it->first.ToString() + " " + it->second.back();
}

ostream& operator<<(ostream& stream, const pair<Date, string>& entry) {
    stream << entry.first << " " << entry.second;
    return stream;
}

ostream& operator<<(ostream& stream, const vector<string>& entry) {
    for (auto& to_print : entry) {
    stream << entry;
    }
    return stream;
}

