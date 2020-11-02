#include <iostream>
#include <map>

using namespace std;

map <char , int> BuildCharCounters(const string& word)
{
    map <char, int > counters;
        for ( const char& c : word) {
        ++counters[c];
        }
        return counters;
}

int main() {
    int Q;
    string word_1, word_2;
    cin >> Q;
    while ( Q != 0) {
        cin >> word_1 >> word_2;
        BuildCharCounters(word_1);
        BuildCharCounters(word_2);
        if (BuildCharCounters(word_1) == BuildCharCounters(word_2)) {
            cout << "YES"<< endl;
        }
        else cout << "NO" << endl;
        --Q;

    }

    return 0;
}