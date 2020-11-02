#include <iostream>
#include <vector>
#include <map>
#include <tuple>

bool operator <(const Region& lhs, const Region& rhs) {
    auto lhs_key = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
    auto rhs_key = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
    return lhs_key < rhs_key;
}
int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    int count = 0;
    map <Region, int> repetition_count;
    for (const Region& x : regions) {
        count = ++repetition_count[x];
        result = max(result, count);
    }
    return result;
}