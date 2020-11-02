#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using  namespace std;

using namespace std::chrono;

void Print (const vector<int>& v) {
    for (const auto& i : v ) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    int N;
    vector<int> num;
    cin >> N;


    for (int i = 0; i < N ; ++i) {
        int n;
        cin >> n;
        num.push_back(n);
    }


    //auto start = steady_clock::now();
    sort (begin(num), end(num), [](int x, int y) { return abs(x) < abs(y); }) ;




    Print(num);
    //auto finish = steady_clock ::now();
    //cout << duration_cast<nanoseconds>(finish - start).count();
    return 0;
}