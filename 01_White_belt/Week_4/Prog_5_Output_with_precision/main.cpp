#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ifstream input ("input.txt");
    double value = 0 ;
    string line = "";
    cout << fixed << setprecision(3);

            while (input >> value) {

                cout << value << endl;
            }




    return 0;
}