#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
    string name;
    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;
        } else {
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
    Person  (const string& first_name, const string& last_name, const int& born_year)   {

        first_names[born_year] = first_name ;
        last_names[born_year] = last_name;
        data_born_year = born_year;
        for (const auto i : first_names) {
                if (i.first < born_year) { first_names[born_year].erase(i.first); }
        }
        for (const auto x : last_names) {
            if (x.first < born_year) { first_names[born_year].erase(x.first); }
        }


    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year >= data_born_year) {
            first_names[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= data_born_year) {
            last_names[year] = last_name;
        }
    }
    string GetFullName(int year) const {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны

        if (year < data_born_year )
        {
            return "No person";
            //if (first_name.empty() && last_name.empty())
        }
            if (first_name.empty() && last_name.empty()) {
                return "Incognito";
             }

        else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) const {

        vector <string> names_history = GetHystoryName(first_names, year);
        vector <string> surnames_history = GetHystoryName(last_names, year);

        string all_changes_names;
        string all_changes_surnames;
        if (year < data_born_year )
        {
            return "No person";

        }
        else if (names_history.empty() && surnames_history.empty()) {
            return "Incognito";
        }

        else if (names_history.empty()) {
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
    string data_first_name, data_last_name;
    int data_born_year;
};

int main() {
    Person person ("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    person.ChangeFirstName(1959, "Sergeeva");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}