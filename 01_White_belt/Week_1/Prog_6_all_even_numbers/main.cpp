#include <iostream>
using namespace std;

int main() {
    int A, B ;
    cin >> A >> B ;
    do {
        if (A % 2 == 0) {
            cout << A << " ";
        }
        ++A;
    }    while ( A <= B);






    return 0;
}