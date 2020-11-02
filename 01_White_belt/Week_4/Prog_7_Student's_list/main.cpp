#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

};
struct Student {
    string first_name;
    string last_name;
    Date date;

};

void PrintDate ( const vector<Student>& V, int K  ) {
    cout << V[K-1].date.day << "." << V[K-1].date.month << "." << V[K-1].date.year << endl;
}

void PrintName ( const vector<Student>& V, int K) {
    cout << V[K-1].first_name << " " << V[K-1].last_name << endl;
}


int main() {
    int N = 0, K = 0; // number of students, number of request
    string operation_code;
    cin >> N;
    vector <Student> student_list;
    for (int i = 0; i < N; ++i) {
        string first_name, last_name;
        int day = 0, month = 0, year = 0;
        cin >> first_name >> last_name >> day >> month >> year;
        Date date = {day, month, year};
        Student student = {first_name, last_name, date};
        student_list.push_back(student);
    }
    int M = 0;
    cin >> M;
    for (int j = 0; j < M; ++j ) {
        cin >> operation_code >> K;

        if (operation_code == "name" && K > 0
                                    && K <= N) {
            PrintName(student_list, K);
        } else if (operation_code == "date" && K > 0
                                            && K <= N) {
            PrintDate(student_list, K);
        } else {
            cout << "bad request" << endl;
        }

    }
    return 0;
}