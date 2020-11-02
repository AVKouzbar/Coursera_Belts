#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct WordConstruct {

    string AddFirstWord (const string& s) {
        auto space_iter = find(begin(s), end(s), ' ');
        for (auto iter = begin(s); iter != space_iter; ++iter) {
            result.push_back(*iter);
        }
        return result;
    }

    void AddOtherWords(const string& s) {
        string s_result;
        auto iter = find(begin(s), end(s), ' ');
            while ( iter != end(s)) {
                iter++;
                auto iter2 = find(iter + 1, end(s), ' ');
                for (iter; iter != iter2; iter++) {
                    s_result.push_back(*iter);
                }
                result_.push_back(s_result);
                s_result.erase();
            }
        }

    void CreateVector(const string& s, const vector<string> v) {
        parsed_words.push_back(result);
        for (auto x : result_) {
            parsed_words.push_back(x);
        }
    }
    string result;
    vector <string> result_;
    vector <string> parsed_words;
};

vector<string> SplitIntoWords(const string& s) {
    WordConstruct wordConstruct;
    wordConstruct.AddFirstWord(s);
    wordConstruct.AddOtherWords(s);
    wordConstruct.CreateVector(wordConstruct.result, wordConstruct.result_);
    return wordConstruct.parsed_words;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
