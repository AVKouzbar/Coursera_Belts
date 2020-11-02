#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

void GetIncorrectDate (const string& command, const string& operation) {
    string s_date;
    for (int i = operation.size() + 1; i < command.size(); ++i) {
        if (command[i] != ' ') {
            s_date += command[i];
        } else break;
    }
    throw  runtime_error("Wrong date format: "+ s_date);
}

class Date {
public:
    int GetYear(const int& d, Date& date) const {
        date.year = d;
        return date.year;
    };
    int GetMonth(const int& m, Date& date) const {
        if (m > 0 && m <= 12 ){
            date.month = m;
            return date.month;
        } else throw runtime_error("Month value is invalid: " + to_string(m));
    };
    int GetDay(const int& d, Date& date) const{
        if (d > 0 && d <= 31) {
            date.day = d;
            return date.day;
        } else throw runtime_error("Day value is invalid: " + to_string(d));
    };

    int year = 0;
    int month = 0;
    int day = 0;
};

Date IfCorrectAndInputDay (const string& date, const string& command, const string& operation ) {
    istringstream date_stream(date);
    int y, m, d;
    char def1, def2;
    Date day;
        if (date_stream >> y >> def1 >> m >> def2 >> d && date_stream.eof()) {

                day.GetYear(y, day);
                day.GetMonth(m, day);
                day.GetDay(d, day);

        } else GetIncorrectDate(command, operation);
    return day;
}

bool operator<(const Date& lhs, const Date& rhs){   //Перегрузим для ключа в map
    if (lhs.year == rhs.year && lhs.month == rhs.month) {
        return lhs.day < rhs.day;
    } else if (lhs.year == rhs.year) {
        return lhs.month < rhs.month;
    }
    return lhs.year < rhs.year;
};

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        All_data[date].insert(event);
    };

    bool DeleteEvent(const Date& date, const string& event){
        if (All_data[date].count(event) > 0) {
        All_data[date].erase(event);
            return true;
        } else return false;

    };

    int  DeleteDate(const Date& date) {
        int count_events = All_data[date].size();

            All_data.erase(date);

        return count_events;
    };

    void Find(const Date& date) const {
        if (All_data.count(date) > 0) {
            for (const auto &S : All_data.at(date)) {
                cout << S << endl;
            }
        }
    };

    void Print() const{
        for (const auto& date : All_data) {
            Date print_date = date.first;

            for (const auto& event : All_data.at(print_date)) {
                cout << setw(4) << setfill('0') << print_date.year <<
                  "-" << setw(2) << setfill('0') << print_date.month <<
                  "-" << setw(2) << setfill('0') << print_date.day <<
                  " " << event << endl;
            }
        }
    };

private:
    map <Date, set<string>> All_data;
};

int main() {
    Database db;
    Date date;
    string command;
    while (getline(cin, command)) {
        istringstream ss(command);
        string operation;
        ss >> operation;
        if (operation == "Add") {
            try {
               string date_stream;
               ss >> date_stream;
               date = IfCorrectAndInputDay(date_stream, command, operation);
                } catch (runtime_error& e) {
                    cout << e.what() << endl;
                return  0;
                }
            string event;
            while (ss) {
                ss >> event;
                db.AddEvent(date, event);
            }

    } else if (operation == "Del") {
            try {
                string date_stream;
                ss >> date_stream;
                date = IfCorrectAndInputDay(date_stream, command, operation);
            } catch (runtime_error& e) {
                cout << e.what() << endl;
                return 0;
            }
            string event;
            if (ss >> event) {
                if (db.DeleteEvent(date, event)) {
                    cout << "Deleted successfully" << endl;
                } else {     cout << "Event not found" << endl;      }
            }
            else {
                int count_deleted_events = db.DeleteDate(date);
                cout << "Deleted " << count_deleted_events << " events" << endl;
            }
        }
        else if (operation == "Find"){
            try {
                string date_stream;
                ss >> date_stream;
                date = IfCorrectAndInputDay(date_stream, command, operation);
            } catch (runtime_error& e) {
                cout << e.what() << endl;
                return 0;
            }
            db.Find(date);
        }
        else if (operation == "Print") {
            db.Print();
        }
        else if (operation == "") {

        }
        else {
            cout << "Unknown command: " << operation;
        }
    }
    return 0;
}