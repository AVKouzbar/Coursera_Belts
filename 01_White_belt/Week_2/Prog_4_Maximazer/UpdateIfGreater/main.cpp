#include <iostream>

using  namespace std;

void UpdateIfGreater(int first, int& second) {
    if (first > second) {
        second = first ;
    }
}

int main() {

    int b = 2;
    UpdateIfGreater(-1, b);
    cout << b;
    return 0;
}