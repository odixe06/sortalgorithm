#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono> 

using namespace std;
using namespace chrono; 

const int soday = 10;
const int sophantu = 1000000;

void mergepart(vector<double> &a, vector<double> &temp, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= r) {
        temp[k++] = a[j++];
    }

    for (int m = l; m <= r; m++) {
        a[m] = temp[m];
    }
}

void mergesort(vector<double> &a, vector<double> &temp, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergesort(a, temp, l, mid);
    mergesort(a, temp, mid + 1, r);
    mergepart(a, temp, l, mid, r);
}

int main() {
    freopen("data.txt", "r", stdin);
    freopen("mergesort.txt", "w", stdout);

    vector<double> a(sophantu);
    vector<double> temp(sophantu); 

    for (int i = 0; i < soday; i++) {
        for (int j = 0; j < sophantu; j++) {
            if (!(cin >> a[j])) {
                cerr << "error" << endl;
                return 1;
            }
        }

        auto start = high_resolution_clock::now();

        mergesort(a, temp, 0, sophantu - 1);

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
