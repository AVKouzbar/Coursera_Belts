//
// Created by Loathem on 12.06.2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> storage;

    for (int i = v.size() - 1; i >= 0 ; --i  )  {
        storage.push_back(v[i]);
    }
    return storage;

}