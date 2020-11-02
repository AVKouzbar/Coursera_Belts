#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <numeric>
#include <string>

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
        return num;
    }

private:
    int num = 0, den = 0;
};

#define ASSERT_EQUAL(x, y) {                                           \
ostringstream os;                                                      \
os << #x << " != " << #y << ", " <<__FILE__ << ": " << __LINE__;          \
AssertEqual(x, y, os.str());                                           \
}



void TestPredefined() {
    const string file = __FILE__;
    const int line = __LINE__;
    ASSERT_EQUAL(Rational(1, 1).Numerator(), 1);
    ASSERT_EQUAL(Rational(1, 1).Denominator(), 1);
    ASSERT_EQUAL(Rational(3, 5).Numerator(), 3);
    ASSERT_EQUAL(Rational(3, 5).Denominator(), 5);
    AssertEqual(Rational(2147483647, 2147483647).Numerator(), 1, "Canonical form of 2147483647/2147483647 is 1/1");
    AssertEqual(Rational(2147483647, 2147483647).Denominator(), 1, "Canonical form of 2147483647/2147483647 is 1/1");
    AssertEqual(Rational(-5, 4).Numerator(), -5, "Canonical form of -5/4 is -5/4");
    AssertEqual(Rational(-5, 4).Denominator(), 4, "Canonical form of -5/4 is -5/4");
    AssertEqual(Rational(5, -4).Numerator(), -5, "Canonical form of 5/-4 is -5/4");
    AssertEqual(Rational(5, -4).Denominator(), 4, "Canonical form of 5/-4 is -5/4");
    AssertEqual(Rational(-6, -2).Numerator(), 3, "Canonical form of -6/-2 is 3/1");
    AssertEqual(Rational(-6, -2).Denominator(), 1, "Canonical form of -6/-2 is 3/1");
    AssertEqual(Rational(21, 56).Numerator(), 3, "Canonical form of 21/56 is 3/8");
    AssertEqual(Rational(21, 56).Denominator(), 8, "Canonical form of 21/56 is 3/8");
    AssertEqual(Rational(0, 100).Numerator(), 0, "Canonical form of 0/100 is 0/1");
    AssertEqual(Rational(0, 100).Denominator(), 1, "Canonical form of 0/100 is 0/1");
    AssertEqual(Rational().Numerator(), 0, "Canonical form of default constructed is 0/1");
    AssertEqual(Rational().Denominator(), 1, "Canonical form of default constructed is 0/1");
}

#define RUN_TEST(runner, func) \
runner.RunTest (func, #func)

int main() {
    TestRunner runner;
    RUN_TEST(runner, TestPredefined);
    return 0;
}