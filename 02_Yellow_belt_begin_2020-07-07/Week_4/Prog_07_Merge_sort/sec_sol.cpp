
#include <iostream>
#include <vector>
#include <algorithm>

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
    // Разбить вектор на три равные части.
    auto one_third_part = elements.begin() + range_length / 3;
    auto two_third_part = elements.begin() + range_length * 2 / 3;

    // Вызвать функцию MergeSort от каждой части вектора.
    MergeSort(elements.begin(), one_third_part);
    MergeSort(one_third_part, two_third_part);
    MergeSort(two_third_part, elements.end());

    //Слить первые две трети вектора с помощью алгоритма merge,
    // сохранив результат во временный вектор с помощью back_inserter.
    vector<typename RandomIt :: value_type> temporary_vector;
    merge(begin(elements), one_third_part, one_third_part, two_third_part, back_inserter(temporary_vector));

    //Слить временный вектор из предыдущего пункта с последней третью вектора из п. 2,
    // записав полученный отсортированный диапазон вместо исходного.
    merge(begin(temporary_vector), end(temporary_vector), two_third_part, end(elements), range_begin);
}