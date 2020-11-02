#include <iostream>
#include <map>
#include <string>

using namespace std;

void Change_Capital (map<string,string>& Countries_and_Capitals,
        const string& country, const string& new_capital) {

    if (Countries_and_Capitals.count(country) == 0) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl; // Разобраться с условием

    }
    else {
        string old_capital;
        old_capital = Countries_and_Capitals[country];
        if (old_capital == new_capital) {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        }
        else {
            cout << "Country " << country << " has changed its capital from " <<
            old_capital << " to " << new_capital <<endl;
        }

    }

    Countries_and_Capitals [country] = new_capital;
}

void RenameOldCountry (map <string, string>& Countries_and_Capitals, const string old_country_name,
const string new_country_name) {
    if (old_country_name == new_country_name || Countries_and_Capitals.count(old_country_name) == 0 ||
    Countries_and_Capitals.count(new_country_name) == 1) {
        cout << "Incorrect rename, skip" << endl;
    }
    else {
        cout << "Country " << old_country_name<< " with capital " << Countries_and_Capitals[old_country_name]<<
        " has been renamed to "<< new_country_name <<endl;
        Countries_and_Capitals[new_country_name] = Countries_and_Capitals[old_country_name];
        Countries_and_Capitals.erase(old_country_name);

    }

}

void About_country (map <string,string>& m, const string& country) {
    if (m.count(country) == 0) {
        cout << "Country "<< country<< " doesn't exist" <<endl;
    }
    else {
        cout << "Country " << country << " has capital " << m [country] << endl;
    }

}

void Print_map (const map<string,string>& m) {    // Нужно избавиться от пробела в конце вывода DUMP
    int i = 0;
    for (auto item : m) {
        if (  i < m.size() - 1 ) {

            cout << item.first << "/" << item.second << " ";;
        }
        else {
        cout << item.first << "/" << item.second;
        }
++i;
    }
    cout << endl;
}

int main() {
    int Q = 0;
    string command;
    map <string, string> Countries_and_Capitals;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            string country, capital;
            cin >> country >> capital ;
            Change_Capital(Countries_and_Capitals, country, capital);

        }
        else if (command == "RENAME") {
            string old_country, new_country;
            cin >> old_country >> new_country;
            RenameOldCountry(Countries_and_Capitals, old_country,new_country);

        }
        else if (command == "ABOUT") {
            string country;
            cin >> country;
            About_country(Countries_and_Capitals,country);
        }
        else if (command == "DUMP") {
            if (Countries_and_Capitals.size() == 0) {
                cout << "There are no countries in the world" << endl;
            }
            else {
               Print_map(Countries_and_Capitals);
            }
        }

    }




    return 0;
}