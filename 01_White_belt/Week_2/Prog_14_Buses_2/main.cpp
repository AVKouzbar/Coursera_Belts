#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;




int main() {
    map <vector<string>, int > Buses;
    int Q = 0, N = 0;
    string name_stop;
    vector <string> storage_names_stops;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> N;
        for (int j = 0; j < N; j++ ) {
            cin >> name_stop;
            storage_names_stops.push_back(name_stop);
        }
        if (Buses.count(storage_names_stops) != 0 ) {
            cout << "Already exists for " << Buses[storage_names_stops] << endl;
        }

        else if (Buses.count(storage_names_stops) == 0) {
            int count_buses = Buses.size();
            Buses[storage_names_stops] = count_buses + 1;

                cout << "New bus "<< Buses[storage_names_stops] << endl;
            }
        storage_names_stops.clear();

    }




    return 0;
}