#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono> 

using namespace std;
using namespace chrono; 

const int soday = 10;
const int sophantu = 1000000;


int main() {
    freopen("data.txt", "r", stdin);
    freopen("csorted.txt", "w", stdout);

    vector<double> a(sophantu);

    for (int i = 0; i < soday; i++) {
        for (int j = 0; j < sophantu; j++) {
            if (!(cin >> a[j])) {
                cerr << "Lỗi đọc dữ liệu!" << endl;
                return 1;
            }
        }

       
        auto start = high_resolution_clock::now();
        
        sort(a.begin(), a.end());

        
        auto end = high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();

        
        for (int j = 0; j < sophantu; j++) {
            cout << a[j] << " ";
        }
        cout << endl;

        
        cerr << "Lần " << i + 1 << ": " << duration << " ms" << endl;
    }

    return 0;
}
