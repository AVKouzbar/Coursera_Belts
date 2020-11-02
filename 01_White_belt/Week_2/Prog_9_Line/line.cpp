#include <iostream>
#include <vector>

using namespace std;

int main() {
    int Q, value;
    string command;
    vector<bool> line ;
    cin >> Q;
    for (int i=0; i < Q; ++i) {
        cin >> command;

         if (command == "WORRY_COUNT") {
            int result = 0;
             for (int j = 0; j < line.size() ; ++j) {
                 if (line[j] == true) {
                     result++;
                 }
             }
             cout << result << endl;
             i++;
             if ( i == (Q - 1) ) { break ;
             }
             else
             { cin >> command;}
         }



             cin >> value;
             if (command == "COME") {
                 line.resize(line.size() + value);
             } else if (command == "WORRY") {
                 line[value] = true;
             } else if (command == "QUIET") {
                 line[value] = false;
             }


    }
    return 0;
}