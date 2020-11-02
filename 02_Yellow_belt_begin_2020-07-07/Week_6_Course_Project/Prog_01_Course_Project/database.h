#pragma once

#include "date.h"


#include "node.h"

#include <memory>
#include <functional>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Database {

public:

    Database () {};
    void Add (const Date& date, const string& event);
    void Print(ostream& os) const;

    template <typename Func>
    int RemoveIf(Func predicate) {
        //auto start_rem = steady_clock::now();
        int count = 0;


        for (auto& [date, vector_events] : storage) {    // Подумать, как спрятать в срр, используя function
            vector <string> events_to_remove;
            for (auto& str_event : vector_events) {
                if (predicate(date, str_event)) {
                    events_to_remove.push_back(str_event);
                    pointer[date].erase(str_event);
                    ++count;
                }
            }
                 if (!events_to_remove.empty()) {
                     auto del_condition = [&events_to_remove](const string& event_){
                         for (auto& event_to_remove : events_to_remove ) {
                            if (event_to_remove == event_){
                                return true;
                            }
                         }
                         return false;
                     };
                 auto it_del = remove_if(vector_events.begin(), vector_events.end(), del_condition);
                     vector_events.erase(it_del, vector_events.end());
                 }
            }
        for (auto it_date_to_del = storage.begin(); it_date_to_del != storage.end();) {
            if (it_date_to_del->second.empty()) {
                it_date_to_del = storage.erase(it_date_to_del);
            } else
                ++it_date_to_del;
        }
//        auto finish_rem = steady_clock::now();
//        cout <<"RemoveIf: " << duration_cast<microseconds>(finish_rem - start_rem).count() << " mcs" << endl;
    return count;
    }

    template <typename Func>
    vector<string> FindIf(Func predicate ) const {
        //auto start_find = steady_clock::now();
        vector <string> to_print;
        for( const auto& events_ : storage ) {
            for (const auto& event_ : events_.second) {
                if (predicate(events_.first, event_)) {
                    to_print.push_back(events_.first.ToString() + ' ' + event_);
                }
            }
        }
//        auto finish_find = steady_clock::now();
//        cout <<"FindIf: " << duration_cast<microseconds>(finish_find - start_find).count() << " mcs" << endl;
        return to_print;
    }

    string Last(const Date& date) const;

private:

    map<Date, vector<string>> storage;
    map<Date, set<string>> pointer;

};

//ostream& operator<<(ostream& stream, const pair<Date, Events>& entry);

ostream& operator<<(ostream& stream, const vector<string>& entry);