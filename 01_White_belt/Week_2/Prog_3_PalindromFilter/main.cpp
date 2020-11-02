#include <iostream>
#include <vector>
#include <string>



using namespace std;

vector<string> PalindromFilter (vector <string> words, int minLenght) {

    vector <string> Result;
    bool Condition;
    for (auto w : words) {
    Condition = true;

        for (int i = 0; i < w.size() / 2; ++i) { // Ищем палиндром
            if (w[i] != w[w.size() - i - 1]) {
            Condition = false ;
            }
                    }
        int c = w.size() ;
        if (w.size()  >= minLenght && Condition == true) {  // условие минимальной длины палиндрома
            Result.push_back(w) ;
        }
    }
    return Result;
};

int main() {
    vector<string> V ({"weew", "bro", "code"}) ;
    PalindromFilter(V, 4);
    return 0;
}