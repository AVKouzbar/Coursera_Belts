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

ostream& operator <<(ostream& stream, const Rational& rational ) {
    stream << rational.num << "/" << rational.den;
    return stream;
}

istream& operator >>(istream& stream, Rational& rational ) {

        stream >> rational.num;
        stream.ignore(1);
        stream >> rational.den;
        rational.Init(rational.num, rational.den);


    return stream;
}


int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("-25/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "-25/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
