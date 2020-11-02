#include <iostream>

using namespace std;

int main() {
    double N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y ;

    if (A < B) {            // условие задачи

        if (N > A && N < B || N > A && N == B) {
            cout << N - (N / 100 * X );
        }
        else if (N > B) {
            cout << N - (N / 100 * Y );
        }
        else {
            cout << N;
        }
    }

    return 0;
}