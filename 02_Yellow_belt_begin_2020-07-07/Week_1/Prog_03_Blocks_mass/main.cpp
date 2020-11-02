#include <iostream>
#include <vector>





using namespace std;



int main() {
    int N = 0, Density = 0;
    uint64_t W = 0, H = 0, D = 0;
    uint64_t Mass = 0;
    cin >> N >> Density;
    for (int i = 0; i < N; ++i){
        cin >> W >> H >> D;
        Mass += W * H * D * Density;
    }
    cout << Mass;
    return 0;
}