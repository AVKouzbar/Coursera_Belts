#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void PrintVector (const vector<int>& temperatureValue) {
    for (int s : temperatureValue) {
        cout << s << " " ;
    }
}

int MeanValue (const vector<int>& temperatureValue) {
    int mean = 0;
    for (int i = 0; i < temperatureValue.size(); i++) {
        mean += temperatureValue[i];
        }
    return mean /= temperatureValue.size();

}

vector<int> MorethanMean (const vector<int>& temperatureValue) {
    vector<int> result;
    int mean = MeanValue(temperatureValue);
    for (int i = 0; i < temperatureValue.size(); i++) {
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
   // auto start = steady_clock::now();
    cout << MorethanMean(temperatureValue).size()<< endl;
//    auto finish = steady_clock::now();
   // cout << "MorethanMean = " << duration_cast<microseconds>(finish-start).count()
     //    << "us" << endl;

  //  start = steady_clock::now();
    PrintVector(MorethanMean(temperatureValue));
   // finish = steady_clock::now();
    //cout << "PrintVector = " << duration_cast<microseconds>(finish-start).count()
      //   << "us" << endl;

    return 0;
}