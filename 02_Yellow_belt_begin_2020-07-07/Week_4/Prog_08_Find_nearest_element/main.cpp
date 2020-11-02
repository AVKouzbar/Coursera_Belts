#include <iostream>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(
        const set<int>& numbers,
        int border){
        auto upper = numbers.lower_bound(border);
        if (upper == numbers.begin()) {
            return upper;
        }
        auto lower = prev(upper);
        if (upper == numbers.end()) {
            return lower;
        }
        bool is_previous = (border - *lower <= *upper - border);
        if (is_previous) {
            return lower;
        } else return upper;
}

// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел



int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
         *FindNearestElement(numbers, 0) << " " <<
         *FindNearestElement(numbers, 3) << " " <<
         *FindNearestElement(numbers, 5) << " " <<
         *FindNearestElement(numbers, 6) << " " <<
         *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}
