#include "rational.h"
#include "test_runner.h"
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



#include "tests.h"




int main() {
    TestRunner runner;
    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    runner.RunTest(TestCancellationRational, "TestCancellationRational");
    runner.RunTest(TestNegativeNumerator, "TestNegativeNumerator");
    runner.RunTest(TestPositiveNumerator, "TestPositiveNumerator");
    runner.RunTest(TestEqualNumenatorByOne, "TestEqualNumenatorByOne");
    return 0;
}