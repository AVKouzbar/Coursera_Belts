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
            string arg = "";
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
    if (lhs.den * rhs.num == 0) {

        throw invalid_argument("Division by zero");
    }
    return  Rational(lhs.num * rhs.den, lhs.den * rhs.num);
}
ostream& operator <<(ostream& stream, const Rational& rational ) {
    stream << rational.num << "/" << rational.den;
    return stream;
}

istream& operator >>(istream& stream, Rational& rational ) {
    int p = 0, q = 0;
    stream >> rational.num;
    stream.ignore(1);
    stream >> rational.den;
    if (rational.den == 0) {
        throw invalid_argument("Invalid argument");
    }
    else {
    rational.Init(rational.num, rational.den);


    return stream;
    }
}

int main()
{
    string command;
    Rational dr1, dr2, dr3;
try {
    cin >> dr1 >> command >> dr2;
} catch (invalid_argument& a){
    cout << a.what() << endl;
    return 0;
}
    if (command == "+") {
        dr3 = dr1 + dr2;
    }
    else if (command == "-") {
            dr3 = dr1 - dr2;
        }
        else  if (command == "*") {
                dr3 = dr1 * dr2;
            }
    else
        try {
             {
                dr3 = dr1 / dr2;
            }
        } catch (invalid_argument& b) {
            cout << b.what() << endl;
            return 0;
        }


    cout << dr3;

    return 0;
}