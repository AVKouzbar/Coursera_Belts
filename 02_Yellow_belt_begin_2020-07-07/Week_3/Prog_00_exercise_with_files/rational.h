#include <numeric>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0 ;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        int gc = gcd(numerator, denominator);
        if (denominator < 0 || (denominator < 0 && numerator < 0)) {
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
    int num = 0, den = 0;
};
