#include <iostream>
#include <vector>
#include <algorithm>

//#include "sec_sol.cpp"

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    int range_length = range_end - range_begin;
    // Если диапазон содержит меньше 2 элементов, выйти из функции.
    if ((range_length) < 2) {
        return;
    }
    // Создать вектор, содержащий все элементы текущего диапазона.
    vector<typename RandomIt :: value_type> elements(range_begin, range_end);
    // Разбить вектор на две равные части.
    auto middle = elements.begin() + range_length / 2;
    MergeSort(elements.begin(), middle);
    MergeSort(middle, elements.end());
    merge(begin(elements), middle, middle, end(elements), range_begin);
//    partition(range_begin, range_end, [](const typename RandomIt :: a,
//                                         const typename RandomIt :: b){
//
//    });
}


int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}