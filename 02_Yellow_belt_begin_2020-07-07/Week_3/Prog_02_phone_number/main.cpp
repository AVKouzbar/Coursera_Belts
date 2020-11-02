#include "phone_number.h"

#include <string>
#include <sstream>
#include <exception>
#include <iostream>


using namespace std;

string GetStringToDef(istringstream& stream) {
    char symbol_stream = '\0';
    string result = "";
    while (stream) {
            stream >> symbol_stream;
            if (symbol_stream != '-')
            {
        result.push_back(symbol_stream);
            } else break;
        }
    if (result == "") {
        throw invalid_argument("");
    } else return result;
}

PhoneNumber::PhoneNumber(const string &international_number) {
    istringstream phone_number_stream(international_number);
    char def1;
    phone_number_stream >> def1;
        if (def1 == '+' ) {
         country_code_ = GetStringToDef(phone_number_stream);
         city_code_ = GetStringToDef(phone_number_stream);
         phone_number_stream >> local_number_;
            if (local_number_ == "") {
                throw invalid_argument("Incorrect! local number is empty ");
            }
        } else throw invalid_argument("Incorrect number format! First char != + ");
}

string PhoneNumber ::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber ::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}

//int main() {
//    try {
//    PhoneNumber phoneNumber("+7 -1233-22");
//    string s = phoneNumber.GetCountryCode();
//
//    cout << phoneNumber.GetCountryCode();
//    } catch (exception const& e) {
//        cout << e.what();
//    }
//
//
//    return 0;
//}