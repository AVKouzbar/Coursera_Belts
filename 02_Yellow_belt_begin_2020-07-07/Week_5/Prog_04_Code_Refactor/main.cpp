//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class People {
//public:
//    People(const string& type, const string& business) : type_(type),
//                                                    business_(business){}
//    virtual void Walk(const string& destination) const = 0;
//
//    string GetType() const {
//        return type_;
//    };
//
//    string GetBusiness() const {
//        return business_;
//    };
//
//private:
//    const string type_;
//    const string business_;
//};
//
//class Student : public People {
//public:
//
//    Student(const string& name_, const string& favouriteSong_) :
//                                                People(name_, "Student"),
//                                                FavouriteSong(favouriteSong_){
//    }
//
//    void Learn() const {
//        cout << GetBusiness() << " " << GetType() << " learns" << endl;
//    }
//
//    void Walk(const string& destination) const override {
//        cout << GetBusiness() << " " << GetType() << " walks to: " << destination << endl;
//        SingSong();
//    }
//
//    void SingSong() const {
//        cout << GetBusiness() << " " << GetType() << " sings a song: " << FavouriteSong << endl;
//    }
//
//private:
//
//    const string FavouriteSong;
//};
//
//
//class Teacher : public People{
//public:
//
//    Teacher(const string& name, const string& subject) : People(name, "Teacher"),
//                                                        Subject(subject) {
//    }
//
//    void Teach() const  {
//        cout << GetBusiness() << " " << GetType() << " teaches: " << Subject << endl;
//    }
//
//    void Walk(const string& destination) const override {
//        cout << GetBusiness() << " " << GetType()<< " walks to: " << destination << endl;
//    }
//
//public:
//    string Subject;
//};
//
//
//class Policeman : public People {
//public:
//    Policeman(const string& name) : People(name, "Policeman") {
//    }
//
//    void Check(People& p) {
//        cout << GetBusiness() << GetType() << " checks "<< p.GetBusiness()<<". "
//        << p.GetBusiness() <<"'s name is: " << p.GetType() << endl;
//    }
//
//
//    void Walk(const string& destination) const override {
//        cout << GetBusiness() << GetType() << " walks to: " << destination << endl;
//    }
//
//
//};
//
//void VisitPlaces(People& p, vector<string> places) {
//    for (const auto x : places) {
//        p.Walk(x);
//    }
//}

#include "test.cpp"

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}