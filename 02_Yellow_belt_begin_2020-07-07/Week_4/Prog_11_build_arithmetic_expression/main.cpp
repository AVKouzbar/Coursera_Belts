#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

struct operation {
    char operand = 0;
    int number = 0;
};


int main() {
    istringstream input();
    int first_number, operation_number;
    cin >> first_number >> operation_number;
    if (operation_number == 0) {
        cout << first_number;
        return 0;
    }
    vector<operation> operation_;
    operation operation;
    for (int i = 0; i < operation_number ; ++i) {
        cin >> operation.operand;
        cin >> operation.number;
        operation_.push_back(operation);
    }
    deque<string> expression;
    expression.push_back(to_string(first_number));
    for (int j = 0; j < operation_.size(); ++j) {
        expression.push_front("(");
        expression.push_back(") ");
        expression.push_back(string(1, operation_[j].operand));
        expression.push_back(" " + to_string(operation_[j].number));
    }
    for (string& s : expression) {
        cout << s;
    }

    return 0;
}