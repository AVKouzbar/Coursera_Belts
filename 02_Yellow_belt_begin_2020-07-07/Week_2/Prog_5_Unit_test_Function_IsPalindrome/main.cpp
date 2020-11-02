#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

bool IsPalindrom(const string& str) {
    // Замечание: более правильным было бы использовать здесь тип size_t вместо int
    // О причинах Вы узнаете на Жёлтом поясе
    for (size_t i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void TestEmptyStringIsPalindrom() {
    AssertEqual(IsPalindrom(""), true, "Empty string is palindrome");
}

void TestOneSymbolIsPalindrom() {
    AssertEqual(IsPalindrom(" "), true, "Single char is palindrome");
}

void TestDetectedAllChar() {
    AssertEqual(IsPalindrom("  war raw  "), true, "Skiped char");
    AssertEqual(IsPalindrom("Madam"), false, "Wrong register");
    AssertEqual(IsPalindrom("XabbaY"), false, "XabbaY is not a palindrome");
    AssertEqual(IsPalindrom("abcderdcba"),0);
    AssertEqual(IsPalindrom("abcdeedcbaz"),0);
    AssertEqual(IsPalindrom("zabcdeedcba"),0);
    AssertEqual(IsPalindrom("777777"),1);
    AssertEqual(IsPalindrom("777778"),0);
    AssertEqual(IsPalindrom("877777"),0);
    AssertEqual(IsPalindrom(""), true, "empty string");
    AssertEqual(IsPalindrom(" "), true, "whitespace");
    AssertEqual(IsPalindrom("A"), true, "A");
    AssertEqual(IsPalindrom("&"), true, "&");
    AssertEqual(IsPalindrom("1"), true, "1");
    AssertEqual(IsPalindrom("121"), true, "121");
    AssertEqual(IsPalindrom("@@"), true, "@@");
    AssertEqual(IsPalindrom("!@# #@!"), true, "!@# #@!");
    AssertEqual(IsPalindrom("madam"), true, "madam");
    AssertEqual(IsPalindrom("baobab"), false, "baobab");
    AssertEqual(IsPalindrom(" weew "), true, " weew ");
    AssertEqual(IsPalindrom("f f ff f f"), true, "f f ff f f");
    AssertEqual(IsPalindrom("f f f f f"), true, "f f f f f");
    AssertEqual(IsPalindrom("A  L L A"), false, "A  L L A");
    AssertEqual(IsPalindrom("mada m"), false, "mada m");
    AssertEqual(IsPalindrom(" weew   "), false, " weew   ");
    AssertEqual(IsPalindrom("   weew "), false, "   weew ");
    AssertEqual(IsPalindrom("qwertyTrewq"), false, "qwertyTrewq");
    AssertEqual(IsPalindrom("qwertytrewq"), true, "qwertytrewq");
    AssertEqual(IsPalindrom("qwerttrewq"), true, "qwerttrewq");
    AssertEqual(IsPalindrom("qwertytrewQ"), false, "qwertytrewQ");
    AssertEqual(IsPalindrom("Q wer ewQ"), false, "Q wer ewQ");
    AssertEqual(IsPalindrom("  "), true, "  ");



}

int main() {
    TestRunner runner;
    runner.RunTest(TestEmptyStringIsPalindrom, "TestEmptyStringIsPalindrom");
    runner.RunTest(TestOneSymbolIsPalindrom, "TestOneSymbolIsPalindrom");
    runner.RunTest(TestDetectedAllChar, "TestDetectedAllChar");
    //cout << IsPalindrom("777777");


    return 0;
}