#include <iostream>
#include <string>
#include <map>

using namespace std;

struct NamesAndSurnames {
    string name;
    string surname;
};

class Person {
public:

    void ChangeFirstName(int year, const string& first_name) {
        if (AllData.count(year) == 0) {AllData[year].surname = "";
        }
        AllData[year].name = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        if (AllData.count(year) == 0) {AllData[year].name = "";}
        AllData[year].surname = last_name;
    }

    string GetFullName(int year) {
        if ( AllData.size() == 0 ) { return  "Incognito"; }
        else  {
            for (const auto& i : AllData) {
                if (year < i.first) return "Incognito";
                break;
            }
        }
        string nm = "";
        string sn = "";
        for (const auto& i : AllData) {
            if (i.first <= year && i.second.surname != "") sn = i.second.surname;

            if (i.first <= year && i.second.name != "") nm = i.second.name;
        }
        if(nm == "") return sn + " with unknown first name";
        else if(sn == "") return nm + " with unknown last name";
        else return nm + " " + sn;

    }

private:
    map <int, NamesAndSurnames> AllData;

};

