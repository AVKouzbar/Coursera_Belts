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

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (auto c : numbers) {cout << c << " ";}
    return 0;
}