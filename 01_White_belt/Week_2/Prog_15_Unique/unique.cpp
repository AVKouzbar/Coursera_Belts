#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    vector <string> Str;
    string S;
    for (int i = 0; i < Q; i++) {

        cin >> S;
        Str.push_back(S);

    }
    set <string> s(begin(Str), end(Str));
    cout << s.size();
    return 0;
}