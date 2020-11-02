#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

class Person {
public:
    void ChangeFirstName (int year, const string& first_name) {
        NamesAndYears[year] = first_name;

    }
    void ChangeLastName (int year, const string& last_name) {
        SurnamesAndYears[year] = last_name;
    }


    string GetFullName (int year) {
        int key_last_name = 0, key_last_surname = 0;
        if (NamesAndYears.empty() == false) {
        itlow = NamesAndYears.lower_bound(year);
        key_last_name = itlow -> first;
        }
        else { key_last_name = 0; }
        if (SurnamesAndYears.empty() == false) {
            itlow_1 = SurnamesAndYears.lower_bound(year);
            key_last_surname = itlow_1->first;
        }
        else { key_last_surname = 0; }

        if (key_last_name <= 1 && key_last_surname <= 1
                                && NamesAndYears[key_last_name].empty()
                                &&SurnamesAndYears[key_last_surname].empty()) {
            return "Incognito";
        }

        else if ( key_last_surname <= 1 && SurnamesAndYears[key_last_surname].empty() ) {
           return NamesAndYears[key_last_name] + " with unknown last name";
        }

        else if (key_last_name <= 1 && NamesAndYears[key_last_name].empty() ) {
            return SurnamesAndYears[key_last_surname] + " with unknown first name";
        }
        else {
            return NamesAndYears[key_last_name] + " " + SurnamesAndYears[key_last_surname];
        }
    }

private:
    map <int, string, greater<int>> NamesAndYears;
    map <int, string, greater<int>> SurnamesAndYears;
    map <int, string, greater<int>> :: iterator itlow;
    map <int, string, greater<int>> :: iterator itlow_1;

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

   /*Person person;

    person.ChangeFirstName(1965, "Polina");
    for (int year : {1964, 1965, 1900}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1965, "Sergeeva");
    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullName(year) << endl;
    }*/

    return 0;
}