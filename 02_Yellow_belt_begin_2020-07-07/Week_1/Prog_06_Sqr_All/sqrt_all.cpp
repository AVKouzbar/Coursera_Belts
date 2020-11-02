#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;


template <typename T>
T Sqr(T x);

template <typename T>
vector<T> Sqr(const vector <T>& value);

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& value);

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& value);

template <typename T>
T Sqr(T x) {
    return x * x;
}

template <typename T>
vector<T> Sqr(const vector<T>& value) {
    vector<T> result;
    for (const T& x : value) {
        result.push_back(Sqr(x));
    }
    return result;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& map1) {
    map <Key, Value> result;
    for (const auto& item : map1) {
        result[item.first] = Sqr(item.second);
    }
    return result;

}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p1) {

    return {Sqr(p1.first), Sqr(p1.second)};
}
