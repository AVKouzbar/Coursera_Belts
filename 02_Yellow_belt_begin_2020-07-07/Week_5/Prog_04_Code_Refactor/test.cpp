#include <iostream>
#include <string>
#include <vector>

using namespace std;


class People
{
public:
    People(const string& name, const string& type) : Name(name), Type(type){}
    virtual void Walk(const string& destination) const
    {
        cout << Type + ": " << Name << " walk to: " << destination << endl;
    }
public:
    const string Name;
    const string Type;
};

class Student : public People {
public:

    Student(string name, string favouriteSong) : FavouriteSong(favouriteSong), People(name, "Student") { }

    void Learn() const {
        cout << "Student: " << Name << " learns" << endl;
    }

    void SingSong() const {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void Walk(const string& destination) const {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        SingSong();
    }

private:
    const string FavouriteSong;
};


class Teacher : public People {
public:

    Teacher(string name, string subject) : People(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }


private:
    const string Subject;

};


class Policeman : public People {
public:
    Policeman(string name) : People(name, "Policeman") {}

    void Check(People p) const {
        cout << "Policeman: " << Name << " checks " << p.Name << ". " << p.Type << "'s name is: " << p.Name << endl;
    }

};


void VisitPlaces(const People& t, const vector<string>& places) {
    for (auto p : places) {
        t.Walk(p);
    }
}

