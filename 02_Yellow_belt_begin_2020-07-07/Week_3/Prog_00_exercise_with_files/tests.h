#include "test_runner.h"

void TestDefaultConstructor() {
    Rational rational;
    AssertEqual(make_pair(rational.Numerator(), rational.Denominator()), make_pair(0, 1));
}

void TestCancellationRational() {
    Rational rational(2, 4);
    AssertEqual(make_pair(rational.Numerator(), rational.Denominator()), make_pair(1, 2));
    Rational rational1(3 , 11);
    AssertEqual(make_pair(rational1.Numerator(), rational1.Denominator()), make_pair(3, 11));
    Rational rational2(1,1);
    AssertEqual(make_pair(rational2.Numerator(), rational2.Denominator()), make_pair(1, 1));
}

void TestNegativeNumerator() {
    Rational rational(1, -1);
    AssertEqual(make_pair(rational.Numerator(), rational.Denominator()), make_pair(- 1, 1));
    Rational rational1 (-1, 1);
    AssertEqual(make_pair(rational1.Numerator(), rational1.Denominator()), make_pair(- 1, 1));
}

void TestPositiveNumerator() {
    Rational rational(-1, -1);
    AssertEqual(make_pair(rational.Numerator(), rational.Denominator()), make_pair( 1, 1));
}

void TestEqualNumenatorByOne() {
    Rational rational(0, 10);
    AssertEqual(make_pair(rational.Numerator(), rational.Denominator()), make_pair( 0, 1));
}