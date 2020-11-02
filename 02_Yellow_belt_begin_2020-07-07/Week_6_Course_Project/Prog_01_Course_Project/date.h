#pragma once

#include <string>
#include <stdexcept>
#include <vector>
#include <iomanip>

using namespace std;

class Date {
public:
    // конструктор выбрасывает исключение, если его аргументы некорректны
    Date(int new_year, int new_month, int new_day) ;

    int GetYear() const ;
    int GetMonth() const ;
    int GetDay() const ;
    string ToString() const {
        ostringstream stream;
        stream << setw(4) << setfill('0') << year << '-'
               << setw(2) << month << '-' << setw(2) << day;
        return stream.str();
    }

private:
    int year;
    int month;
    int day;
};

Date ParseDate(istringstream& is);

bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
ostream& operator<<(ostream& stream, const Date& date);