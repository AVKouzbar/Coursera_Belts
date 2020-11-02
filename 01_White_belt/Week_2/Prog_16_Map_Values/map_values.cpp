#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;


set<string> BuildMapValuesSet(const map<int, string>& m) {
    set <string> Values;

    for (const auto item : m) {
        Values.insert(item.second);
    }
    return Values;

}