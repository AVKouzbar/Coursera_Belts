#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a != b) {
        while (a != 0 && b != 0) {
            if (a > b) {
                a = a % b;
            }
            else {
               b = b % a;
            }
        }
        cout << a + b;
    }
    else cout << a ;
    return 0;
}