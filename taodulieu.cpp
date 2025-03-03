#include <iostream>
#include <cstdio>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int soday = 10;
const int sophantu = 1000000;

int main () {
    freopen ("data.txt", "w", stdout);
    random_device rd;
    mt19937 gen(rd());  
    uniform_real_distribution<double> dist(0.0, 1000000.0); // chọn số thực ngẫu nhiên trong khoảng này

    vector <double> dayso(sophantu);
    for (int i = 1; i <= soday; ++i) {
        for (int j = 0; j < sophantu; ++j) {
            dayso[j] = dist(gen); //dist(gen) dùng để trả về số ngẫu nhiên
        }

    if (i==1) {
        sort(dayso.begin(), dayso.end()); //2 dãy này cần sắp xếp
    }
    else if (i==2) {
        sort(dayso.begin(), dayso.end(), greater<double>()); 
    }
    for (auto e: dayso) cout << e << " ";
    cout << endl;
    }

    fclose (stdout);

    return 0;
}
       