#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> storage;

    for (int i = v.size() - 1; i >= 0 ; --i  )  {
        storage.push_back(v[i]);
    }
    return storage;

}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> s = Reversed(numbers);
    for (auto c : s) {cout << c << " ";}
    return 0;
}