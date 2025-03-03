#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono> 

using namespace std;
using namespace chrono; 

const int soday = 10;
const int sophantu = 1000000;

void quicksort(vector<double> &a, int bd, int kt) {
    if (bd >= kt) return;

    int pivot_index = bd + rand() % (kt - bd + 1);
    double pivot = a[pivot_index];
    swap(a[pivot_index], a[kt]); 

    int i = bd - 1;
    for (int k = bd; k < kt; k++) {
        if (a[k] < pivot) {
            i++;
            swap(a[i], a[k]);
        }
    }
    swap(a[i + 1], a[kt]);

    quicksort(a, bd, i);
    quicksort(a, i + 2, kt);
}

int main() {
    freopen("data.txt", "r", stdin);
    freopen("quicksorted.txt", "w", stdout);

    vector<double> a(sophantu);

    for (int i = 0; i < soday; i++) {
        for (int j = 0; j < sophantu; j++) {
            if (!(cin >> a[j])) {
                cerr << "Lỗi đọc dữ liệu!" << endl;
                return 1;
            }
        }

       
        auto start = high_resolution_clock::now();
        
        quicksort(a, 0, sophantu - 1);

        
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
