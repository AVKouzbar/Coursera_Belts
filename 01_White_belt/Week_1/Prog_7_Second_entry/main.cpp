#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;
    int i = 0, j = 0;
    for (auto c : a ) {
        if (c == 'f') j++ ;
        if (j == 2) {
            cout << i ;
            break;
        }
       i++;
        }
    if (j == 0) cout << -2;
    if (j == 1) cout << -1;


    return 0;
}