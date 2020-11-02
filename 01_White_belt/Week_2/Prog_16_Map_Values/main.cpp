#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set <string> Values;

    for (const auto item : m) {
        Values.insert(item.second);
    }
    return Values;

}


int main() {
    set<string> values = BuildMapValuesSet({
                                                   {1, "odd"},
                                                   {2, "even"},
                                                   {3, "odd"},
                                                   {4, "even"},
                                                   {5, "odd"}
                                           });

    for (const string& value : values) {
        cout << value << endl;
    }

    return 0;
}