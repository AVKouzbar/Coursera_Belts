#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<vector<string>> daysInMonth(31);
    vector<int> monthInYear({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }) ;
    int i, Q;
    int  current_month = 0;
    string command;
    cin >> Q;
    while (Q != 0) {

        cin >> command;
        --Q;
        if (command == "ADD") {
            string s;
            cin >> i;
            cin >> s;
            daysInMonth[--i].push_back(s);

        } else if (command == "DUMP") {
            cin >> i; //
            vector<string>output;
            int k = 0;
            for (auto x : daysInMonth[--i]) {
                output.push_back(x);
                ++k;
            }

            cout <<  k << " ";
            int v = output.size() - 1;
            for (auto x : output)
            {cout << x << " ";}
            cout << endl;

        }

    else if (command=="NEXT") {
        int next_month = current_month + 1;
        int c = monthInYear.size() - 1;

         if (current_month == monthInYear.size() - 1 ) {
             next_month = 0; }
        if (monthInYear[next_month] >= monthInYear[current_month] ) {

                int difference = monthInYear[next_month] - monthInYear[current_month];
                daysInMonth.resize(monthInYear[next_month]);
                if (current_month == monthInYear.size() - 1) {
                    current_month = -1;}

        }
        else if (monthInYear[next_month] < monthInYear[current_month]) {
            int numberOfDaysConserns = monthInYear[current_month] - monthInYear[next_month];
            vector <string> lastDayConserns(0);
            for (int j = numberOfDaysConserns; j > 0; j--)
            {
                //int count = monthInYear[current_month] - j - 1;
                lastDayConserns.insert(end(lastDayConserns), begin(daysInMonth[monthInYear[current_month] - j ]),
                        end(daysInMonth[monthInYear[current_month] - j ]));
            }

            daysInMonth.resize(monthInYear[next_month]); // Изменение кол-ва дней в следующем месяце
            for (auto y : lastDayConserns) {
                daysInMonth[monthInYear[next_month] - 1].push_back(y); }

        }
current_month++;
    }

    }

    return 0;
}