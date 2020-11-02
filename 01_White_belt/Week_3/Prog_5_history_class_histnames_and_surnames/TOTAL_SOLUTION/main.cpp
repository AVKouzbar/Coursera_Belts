#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}

vector <string> GetHystoryName (const map <int, string>& names, int year) {
    vector <string> data_output;

        for (const auto& x : names) {
            if (x.first <= year) {
            data_output.push_back(x.second);
            }
            else {break; }
        }

    return  data_output;
}

string GetResult (const vector<string> V ) {
    vector <string> data(V.rbegin(), V.rend());
    vector <string> correct_data;

    string result;
    if (data.size() == 1) {data.push_back(data[0]); }
    for (int i = 1; i < data.size(); i++) {
        if (data[i] != data[ i - 1]) {
            correct_data.push_back(data[i]);
           // result += data[i] + " ";
           }
    }
    for (int j = 0; j < correct_data.size(); j++) {     //Избавляемся от лишней запятой
        if (j != correct_data.size() - 1) {
            result += correct_data[j] + ", ";
        }
        else { result += correct_data[j]; }
    }
    if (result.size() != 0) {
    return  " (" + result + ")";
    }
    else {
        return result;
    }


}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) {

        vector <string> names_history = GetHystoryName(first_names, year);
        vector <string> surnames_history = GetHystoryName(last_names, year);

        string all_changes_names;
        string all_changes_surnames;
        if (names_history.empty() && surnames_history.empty()) {
            return "Incognito";
        }   else if (names_history.empty()) {
                all_changes_surnames = GetResult(surnames_history);
                return surnames_history [surnames_history.size() - 1] + all_changes_surnames + " with unknown first name";
        }
            else if (surnames_history.empty()) {
                all_changes_names = GetResult(names_history);
            return names_history[names_history.size() - 1] + all_changes_names + " with unknown last name";
            }
            else {
            all_changes_names = GetResult(names_history);
            all_changes_surnames = GetResult(surnames_history);
            return names_history.back() + all_changes_names + " " + surnames_history.back() + all_changes_surnames;
            }


    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
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

   //-----------------------------------------------------------------------------------------------------
   /* Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;

    return 0;*/
   /* Person person;
    person.ChangeFirstName(1966, "Aglaya");
    person.ChangeFirstName(1962, "Polina");
    person.ChangeFirstName(1963, "Polina");
    person.ChangeFirstName(1964, "Polina");
    person.ChangeFirstName(1961, "Polina");
    person.ChangeLastName(1963, "Sergeeva");
    for (int year : {  1990 }) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;*/






}
