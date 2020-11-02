#include <iostream>
#include <numeric>

using namespace std;

class Rational {
   public:
    Rational() {
         num = 0 ;
         den = 1;
    }
    int num = 0, den = 0;

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


};

Rational operator +(const Rational& lhs, const Rational& rhs) {
        Rational t = Rational(lhs.num * rhs.den + rhs.num * lhs.den, rhs.den * lhs.den);
    return t;
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num * rhs.den - rhs.num * lhs.den, rhs.den * lhs.den );
}

bool operator ==(const Rational& lhs, const Rational& rhs ) {
    if (lhs.den == rhs.den && lhs.num == rhs.num) {
        return true;
    }
    else return false;
}


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
