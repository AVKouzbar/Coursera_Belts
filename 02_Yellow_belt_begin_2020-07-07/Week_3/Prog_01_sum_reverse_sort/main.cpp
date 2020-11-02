
#include <iostream>
#include <algorithm>

#include "sum_reverse_sort.h";

using namespace std;

int Sum(int x, int y) {
    return x + y;
};

string Reverse(string s) {
    reverse(begin(s), end(s));
    return s;
};

void Sort(vector<int>& nums) {
    sort(begin(nums), end(nums));
};


//int main() {
//    cout << Sum(1,2) << endl;
//    cout << Reverse("asdfgh");
//    vector<int> v = {1,3,5,4,2};
//    Sort(v);
//    for (auto& c : v) {
//        cout << c << " ";
//    }
//
//
//    return 0;
//}