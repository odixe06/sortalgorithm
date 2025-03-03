#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono> 

using namespace std;
using namespace chrono; 

const int soday = 10;
const int sophantu = 1000000;

void heapify(vector<double> &a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapsort(vector<double> &a) {
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}


int main() {
    freopen("data.txt", "r", stdin);
    freopen("heapsorted.txt", "w", stdout);

    vector<double> a(sophantu);

    for (int i = 0; i < soday; i++) {
        for (int j = 0; j < sophantu; j++) {
            if (!(cin >> a[j])) {
                cerr << "error" << endl;
                return 1;
            }
        }

       
        auto start = high_resolution_clock::now();
        
        heapsort(a);

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
