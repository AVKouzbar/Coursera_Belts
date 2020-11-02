#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SortedStrings  {
public:
    vector <string> Adding_strings;
    vector <string> Result;
    void AddString (const string& s) {
        Adding_strings.push_back(s);

    }

    vector <string> GetSortedStrings () {
    Result = Adding_strings;
    sort(begin(Result), end(Result));

    return Result ;

    }

} ;

void PrintSortedStrings(SortedStrings& strings) {

    for (const string& s : strings.GetSortedStrings( )) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {

    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);


    return 0;
}