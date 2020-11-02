#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;
    map <set <string>, int> Buses;
    vector <string> Line;
    for (int i = 0; i < q; ++i) {
        int number_stops;
        cin >> number_stops;
        Line.clear();
        for (int j = 0; j < number_stops; ++j) {
            string stop;
            cin >> stop;
            Line.push_back(stop);
        }
        set <string> s(begin(Line), end(Line));

            if (Buses.count(s) == 0) {
                int new_value = Buses.size();
                Buses[s] = new_value;
                cout << "New bus " << Buses.size() << endl;
            }
            else {
                cout << "Already exists for " << Buses[s] + 1 << endl;

            }


    }




    return 0;
}