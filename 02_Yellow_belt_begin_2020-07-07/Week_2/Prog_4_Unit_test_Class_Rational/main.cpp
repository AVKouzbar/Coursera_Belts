#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>
#include <utility>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template <class F, class S>
ostream& operator << (ostream& os, const pair<F, S>& m) {
    os << "{";
        os << m.first << " " << m.second;

    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

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

int main() {
    TestRunner runner;
    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    runner.RunTest(TestCancellationRational, "TestCancellationRational");
    runner.RunTest(TestNegativeNumerator, "TestNegativeNumerator");
    runner.RunTest(TestPositiveNumerator, "TestPositiveNumerator");
    runner.RunTest(TestEqualNumenatorByOne, "TestEqualNumenatorByOne");
    return 0;
}