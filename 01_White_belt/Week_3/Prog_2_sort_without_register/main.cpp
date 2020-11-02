#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

void Print (const vector<string>& v) {
    for (const auto& i : v ) {
        cout << i << " ";
    }
}


string get_low (const string& S) {
    string result;
    for (char x : S) {
        result += tolower(x);
    }
    return result;

}

int main() {
    int n;
    cin >> n;
    vector <string> s(n);



        for (string& x : s) {
            cin >> x;
        }

        sort(begin(s), end(s), [](string& x, string& y) {
            return get_low(x) < get_low(y); } );

    Print(s);




    return 0;

}