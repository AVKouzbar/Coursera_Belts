//
// Created by Loathem on 12.06.2020.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings (vector<string>& source, vector<string>& destination ) {
    for (auto c : source) {
        destination.push_back(c);
    }
    source.clear();
}
