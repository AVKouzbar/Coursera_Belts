#include <iostream>
#include <vector>
#include <map>
#include <string>

using  namespace std;

map <vector<string>, string> BuildReversedMap(const map <string, vector<string>>& m) {
    map <vector<string>, string> result;
    for (auto item : m) {
        result[item.second] = item.first;
    }
    return result;
}

int main() {
    int Q;
    map <string, vector<string>> Buses;
    vector<string> Order_Bus_number;
    string command;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == "NEW_BUS") {
            vector <string> bus_stops;
            int stop_count = 0;
            string stops, bus_number;
            cin >> bus_number;
            Order_Bus_number.push_back(bus_number);
            cin >> stop_count;
            for (int i = 0; i < stop_count; i++) {
                cin >> stops;
                bus_stops.push_back(stops);
            }
        Buses [bus_number] = bus_stops;
        }
        //----------------------------------------------------------------------------------
        else if (command == "BUSES_FOR_STOP"){
        vector <string> Not_Order_bus_number;
        string stop;
        int N = 0;
        cin >> stop;
        map <vector<string>, string> ReversedMap;
        ReversedMap = BuildReversedMap(Buses);
        for (const auto& v :  ReversedMap) {
            vector <string> s = v.first;
            for (int i = 0; i < v.first.size() ; i++) { //         Нужна ли -1? ?
               if (s[i] == stop) {
                  //cout << v.second << " ";
                  Not_Order_bus_number.push_back(v.second);
                  N++;
                }
            }
        }
            if (N == 0){
                cout << "No stop";}
        for (int i = 0; i < Order_Bus_number.size() ; i++) {
            for (int j = 0; j < Not_Order_bus_number.size() ; j++) {

                if (Order_Bus_number[i] == Not_Order_bus_number[j]) {
                    cout << Order_Bus_number[i] << " "; //Нужно опять избавиться от пробела
                }
            }
        }
            cout << endl;
        N = 0;
        }

    else if (command == "STOPS_FOR_BUS") {
        string bus_number;
        cin >> bus_number;
        int j = 0;
        int count = 0; // Счетчик для условия "нет пересадки"

        map <vector<string>, string> Reversed_Buses_map ;
        vector <string> Not_Order_bus_number;
        Reversed_Buses_map = BuildReversedMap(Buses);
        if (Buses.count(bus_number) == 0) {cout << "No bus" << endl;}
        else {
            for (const auto &number_item : Buses) {       // Ищем по ключу номер автобуса
                if (number_item.first == bus_number) {   //Если нашли
                    for (int k = 0; k < number_item.second.size(); k++) {

                        cout << "Stop " << number_item.second[j] << ": ";  // Выводим по порядку названия остановок
                        //cout << "done";

                        for (const auto &stops_item : Reversed_Buses_map) { //Ищем по обратному словарю по ключам остановок
                            for (int i = 0; i < stops_item.first.size(); i++) { // Ищем в каждом векторе остановок

                                if (stops_item.first[i] ==
                                    number_item.second[j]) {  // Совпадение с выведенной нами остановкой
                                    if (stops_item.second != bus_number) {
                                        Not_Order_bus_number.push_back(
                                                stops_item.second); // Добавляем в вектор для предстоящей сортировки
                                        ++count;
                                    }
                                }
                            }
                        }
                        if (count == 0) {
                            cout << "no interchange";
                        }
                        for (int i = 0; i < Order_Bus_number.size(); i++) {
                            for (int n = 0; n < Not_Order_bus_number.size(); n++) {

                                if (Order_Bus_number[i] == Not_Order_bus_number[n]) {
                                    cout << Order_Bus_number[i] << " "; //Нужно опять избавиться от пробела
                                }
                            }
                        }

                        Not_Order_bus_number.clear();
                        count = 0;
                        j++;
                        cout << endl;
                    }

                }

            }
        }
    }

    else if (command == "ALL_BUSES") {
        if (Buses.empty()) {
            cout << "No buses"<< endl;
        }
        else {
            for (const auto& item : Buses) {
                cout << "Bus " << item.first <<": ";
                for (const string c : item.second) {
                    cout << c << " ";
                }
                cout << endl;
            }
        }
    }
    }

    return 0;
}