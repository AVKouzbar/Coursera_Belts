#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, c ;

    vector <int> binary_reverse;
    vector <int> binary ;
    cin >> N;
    for (int i = 0; N != 0 ; ++i) {


    c = N % 2;
    N /= 2;

    binary_reverse.push_back(c);
    // cout << binary_reverse [i] ;

    if (N==0) {
        // cout << endl;
        int j = 0;
        do  {
        binary.push_back(binary_reverse[i]);
        cout  << binary [j] ;
        --i;
        ++j;
        } while (i >= 0);
    }
    }



    return 0;
}