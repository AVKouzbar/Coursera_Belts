#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

//vector<int> GenerateRandomArray (int& N) {
//    vector<int> v(N);
//    for (int i = 0; i < N; ++i) {
//        v[i] = 1 + rand() % 7;
//    }
//    return v;
//}

vector<int> GenerateArray (int& N) {
    vector<int> result;
    for (int i = 0; i < N; ++i) {
        result.push_back(i + 1);
    }
    //sort(result.rbegin(), result.rend());
    return result;
}

void PrintVector (vector<int>& V) {
    for (auto iV : V ) {
        cout << iV << " ";
    }
    cout << endl;
}

void PrintAllPermutations (vector<int>& target) {
     vector<vector<int>> result;
     do {
         result.push_back(target);
     } while (prev_permutation(target.begin(), target.end()));
     sort(result.rbegin(), result.rend());
     for (auto ires : result) {
         PrintVector(ires);
     }

}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    v = GenerateArray(n);
    PrintAllPermutations(v);

    return 0;
}