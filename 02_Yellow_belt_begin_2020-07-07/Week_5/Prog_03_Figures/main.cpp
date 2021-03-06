#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle (const int& a, const int& b, const int& c) : _a(a), _b(b), _c(c) {
    }
    string Name () const override {
        return triangle;
    }
    double Perimeter() const override {
        double result = _a + _b + _c;
        return result;
    }
    double Area() const override {
        double spr = static_cast<double >(_a + _b + _c) / 2;
        double result = sqrt(spr * (spr - _a)*(spr - _b)*(spr - _c));
        return result;
    }

private:
    const string triangle = "TRIANGLE";
    const int _a = 0;
    const int _b = 0;
    const int _c = 0;
};

class Rect : public Figure {
public:
    Rect (const int& _width, const int& _height) : width(_width), height(_height) {
    }
    string Name () const override {
        return rect;
    }
    double Perimeter() const override {
        double result = static_cast<double>(width + height) * 2  ;
        return result;
    }
    double Area() const override {
        double result = width * height;
        return result;
    }
private:
    const string rect = "RECT";
    const int width = 0, height = 0;
};

class Circle : public Figure {
public:
    Circle (const int& _r) : r(_r) {
    }
    string Name () const override {
        return circle;
    }
    double Perimeter() const override {
        auto result = static_cast<double>( 2 * 3.14 * r);
        return result;
    }
    double Area() const override {
        double result = 3.14 * pow((r), 2);
        return result;
    }
private:
    string circle = "CIRCLE";
    const int r = 0;
};

shared_ptr<Figure> CreateFigure (istringstream& token) {
    string figure;
    token >> figure;
    token >> ws;
    if (figure == "TRIANGLE") {
        int a = 0, b = 0, c = 0;
        token >> a >> b >> c;
        Triangle triangle(a,b,c);
        return make_shared<Triangle>(triangle);
    } else if (figure == "RECT") {
        int w = 0, h = 0;
        token >> w >> h;
        Rect rect(w, h);
        return make_shared<Rect>(rect);
    } else if (figure == "CIRCLE") {
        int r;
        token >> r;
        Circle circle(r);
        return make_shared<Circle>(circle);
    }

}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}