#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int main() {

    int value = 0;
    ifstream input ("input.txt");
    int N = 0; int M = 0;
    input >> N;
    input.ignore(1);
    input >> M;
    for (int i = 0; i < N; i++ ) {
        vector <int> values;
        for (int j = 0; j < M; ++j ) {
            input >> value;
            values.push_back(value);
            input.ignore(1);
            if (j < M - 1) {
                cout  << setw(10) << values[j] <<" ";
            }
            else {cout << setw(10) << values [j] << endl;}
        }
    }
    return 0;
}