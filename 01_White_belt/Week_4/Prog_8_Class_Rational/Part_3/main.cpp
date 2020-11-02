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

Rational operator *(const Rational& lhs, const Rational& rhs) {
    return  Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
    return  Rational(lhs.num * rhs.den, lhs.den * rhs.num);
}
// Вставьте сюда реализацию operator == для класса Rational из второй части

// Реализуйте для класса Rational операторы * и /

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
