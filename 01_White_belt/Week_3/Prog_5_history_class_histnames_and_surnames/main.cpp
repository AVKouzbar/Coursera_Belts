#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct NamesandSurnames {
    string name;
    string surname;
};

NamesandSurnames FindNameByYear (const map <int, NamesandSurnames>&names , int year) {
    NamesandSurnames name;
    for (const auto& item : names) {

        if (item.first <= year) {
            if (item.second.name.empty() == false ) name.name = item.second.name;
            if (item.second.surname.empty() == false )name.surname = item.second.surname;
        }
        else {
            break;
        }
    }
    return name ;
}

string  PrintChangesName (const vector<string>& V, const NamesandSurnames& current_name) {
    string all_changes = "";

    if (V.empty() == false) {

    all_changes += " (";
        for (int i = V.size() - 1; i == 0; --i) {
            if (V[i] != current_name.name) {
                all_changes += V[i] + ", ";
            }
            else break;
        }
        all_changes += ")";
    }
    return all_changes;

}

string  PrintChangesSurname (const vector<string>& V, const NamesandSurnames& current_name) {
    string all_changes = "";

    if (V.empty() == false) {

        all_changes += " (";
        for (int i = V.size() - 1; i == 0; --i) {
            if (V[i] != current_name.surname) {
                all_changes += V[i] + ", ";
            }
            else break;
        }
        all_changes += ")";
    }
    return all_changes;

}


class Person {
public:

    void ChangeFirstName (int year, const string& first_name) {
        AllData [year].name = first_name;
    }
    void ChangeLastName (int year, const string& last_name ) {
        AllData[year].surname = last_name;
    }
    /*string GetFullName (int year) {
        const NamesandSurnames first_and_last_name = FindNameByYear(AllData, year);


        if (first_and_last_name.name.empty() && first_and_last_name.surname.empty()) {
            return "Incognito";
        }
        else if (first_and_last_name.name.empty()) {

            return first_and_last_name.surname + " with unknown first name";
        }
        else if (first_and_last_name.surname.empty()) {
            return first_and_last_name.name + " with unknown last name";
        }
        else {

            return first_and_last_name.name + " " + first_and_last_name.surname;
        }
    }*/

    string GetFullNameWithHistory(int year) {

        const NamesandSurnames first_and_last_name = FindNameByYear(AllData, year);
        vector <string> surnames_history;
        vector <string> names_history;
        for (const auto& item : AllData )
        {
            if  (item.first <= year) {
                if (item.second.surname.empty() == false) {
                    surnames_history.push_back(item.second.surname);
                }
                if (item.second.name.empty() == false) {
                    names_history.push_back(item.second.name);
                }
            }
            //Сделать вектор для вывода истории и лямбду в потоке для формы вывода. Скобки будут, если
            // в векторе последние данные не менялись повторно. Запятая будет пока не последний элемент - 1.
        }

        if (first_and_last_name.name.empty() && first_and_last_name.surname.empty()) {
            return "Incognito";
        }
        else if (first_and_last_name.name.empty()) {
            string out;
            out = PrintChangesSurname(surnames_history, first_and_last_name);
            //PrintVector(surnames_history);

            return first_and_last_name.surname + out + " with unknown first name";
        }
        else if (first_and_last_name.surname.empty()) {
            //PrintVector(names_history);
            string out;
            out = PrintChangesName(surnames_history, first_and_last_name);

            return first_and_last_name.name + out + " with unknown last name";
        }
        else {
            //PrintVector(names_history);
            //PrintVector(surnames_history);

            return first_and_last_name.name + " " + first_and_last_name.surname;



        }

    }

private:
    map <int, NamesandSurnames> AllData;
    NamesandSurnames first_and_last_name;

};

int main() {

    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}

