#include <iostream>
#include <algorithm>
using namespace std;

#define SQR(x) ((x) * (x))

int LogAndReturn (int x) {
    cout << "x = " << x << endl;
    return x;
}


int main() {
    int x = 3;
    int y = LogAndReturn(x);

    unsigned int z = SQR(y++);
 cout << z;
}