//#pragma once
//
//#include <string>
//
//using namespace std;
//
//class Events {
//public:
//    Events(const string& event) : event_(event)
//    {
//      ++entry_;
//    };
//
//    string GetEvent () const {
//        return event_;
//    }
//
//private:
//    unsigned int entry_ = 0;
//    const string event_;
//
//};
//
//ostream& operator<<(ostream& stream, const Events& events);