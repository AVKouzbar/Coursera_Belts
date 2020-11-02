//
// Created by Loathem on 12.06.2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    vector<int> storage;

    for (int i = v.size() - 1; i >= 0 ; --i  )  {
        storage.push_back(v[i]);
    }
    v = storage;
    storage.clear();
}