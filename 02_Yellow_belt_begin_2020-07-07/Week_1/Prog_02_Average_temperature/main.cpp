#include <iostream>
#include <vector>
using namespace std;

void PrintVector (const vector<int>& temperatureValue) {
    for (int s : temperatureValue) {
        cout << s << " " ;
    }
}

int MeanValue (const vector<int>& temperatureValue) {
    int64_t mean = 0;
    int avg = 0;
    for (int i = 0; i < static_cast<int>(temperatureValue.size()); i++) {
        mean += temperatureValue[i];
    }
    avg = mean/static_cast<int>(temperatureValue.size());
    return avg;

}

vector<int> MorethanMean (const vector<int>& temperatureValue) {
    vector<int> result;
    int mean = MeanValue(temperatureValue);
    for (int i = 0; i < static_cast<int>(temperatureValue.size()); i++) {
        if (temperatureValue[i] > mean) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n ;
    vector<int>temperatureValue(n);


    for (int& i : temperatureValue) {
        cin >> i;
    }
    cout << MorethanMean(temperatureValue).size()<< endl;
    PrintVector(MorethanMean(temperatureValue));
    return 0;
}