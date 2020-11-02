#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a,b,c,D, x1, x2;
    cin >> a >> b >> c ;

    D = b*b - 4*a*c;

if (a != 0) {

    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << x1 << " " << x2;
    }

    else if (D == 0) {
        x1 = -b / (2 * a);
        cout << x1;
    }

    else {
        cout << " ";
    }

}

 else if (b !=0 ) {
    x1 = -c/b ;
    cout << x1 ;
}

else {cout << " ";}

return 0;
}