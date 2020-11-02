#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




void PrintVectorPart (const vector<int>& numbers) {
    auto negative_number_it = find_if(begin(numbers), end(numbers),
                                      [](const int& negative){
                                          return negative < 0;
                                      });
    while (negative_number_it != begin(numbers)) {
        negative_number_it--;
        cout << *negative_number_it << " ";
    }

}

int main() {
    PrintVectorPart({6, 1, 8, -5, 4});
    cout << endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    cout << endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    cout << endl;
    return 0;
}
