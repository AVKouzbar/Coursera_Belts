#include <iostream>
#include <sstream>
#include <numeric>
#include <iomanip>


using namespace std;
class Rational {
public:
Rational() {
    num = 0 ;
    den = 1;
}
int num = 0, den = 0;

Rational(int numerator, int denominator) {
    Init(numerator, denominator);
}

void Init (const int& numerator, const int& denominator) {

    int gc = gcd(numerator, denominator);
    if (denominator == 0) {
        string arg = "0";
        throw invalid_argument(arg);
    }
    else if (denominator < 0 || (denominator < 0 && numerator < 0)) {
        num = - numerator / gc;
        den = - denominator / gc;
    } else if (numerator == 0) {
        num = 0;
        den = 1;
    }
    else {
        num =  numerator / gc;
        den =  denominator / gc;
    }

}

int Numerator() const {

    return num ;
}

int Denominator() const {

    return den;
}

private:

};



Rational operator /(const Rational& lhs, const Rational& rhs) {
    if (lhs.den * rhs.num == 0) {
        string arg = "0";
        throw domain_error(arg);
    }
    return  Rational(lhs.num * rhs.den, lhs.den * rhs.num);
}




int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
