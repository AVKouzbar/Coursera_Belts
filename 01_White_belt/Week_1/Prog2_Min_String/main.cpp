#include <iostream>
#include <string>

using namespace std;

int main() {
    string one;
    string two;
    string three;
    cin >> one >> two >> three;
    if (one <= two && one <= three) {
        cout << one;
    }
    else if (two <= one && two <= three) {
        cout << two;
    }
    else cout << three;
    return 0;
}