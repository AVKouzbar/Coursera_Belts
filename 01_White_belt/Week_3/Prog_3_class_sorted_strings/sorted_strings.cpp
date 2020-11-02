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