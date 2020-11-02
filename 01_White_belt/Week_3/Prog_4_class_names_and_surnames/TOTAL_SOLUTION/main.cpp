#include <iostream>
#include <string>
#include <map>

using namespace std;

struct NamesandSurnames {
    string name;
    string surname;
};

NamesandSurnames FindNameByYear (const map <int, NamesandSurnames>&names , int year) {
     NamesandSurnames name;
    for (const auto& item : names) {

        if (item.first <= year) {
            if (item.second.name.empty() != true ) name.name = item.second.name;
            if (item.second.surname.empty() != true )name.surname = item.second.surname;
        }
        else {
            break;
        }
    }
    return name ;
}


class Person {
public:
    void ChangeFirstName (int year, const string& first_name) {
        AllData [year].name = first_name;
    }
    void ChangeLastName (int year, const string& last_name ) {
        AllData[year].surname = last_name;
    }
    string GetFullName (int year) {
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
    }

private:
    map <int, NamesandSurnames> AllData;

};




int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
