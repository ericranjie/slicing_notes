#include <iostream>
using namespace std;

int partition(int r[], int s, int e) {
    int p = r[e];
    int i = s - 1;

    for (int j = s; j < e; j++) {
        if (r[j] <= p) {
            i++;
            int t = r[i];
            r[i] = r[j];
            r[j] = t;
        }
    }

    int t = r[i + 1];
    r[i + 1] = r[e];
    r[e] = t; // POE:

    return i + 1;
}

void quicksort(int r[], int s, int e) {
    if (s < e) {
        int p = partition(r, s, e);
        quicksort(r, s, p - 1);
        quicksort(r, p + 1, e);
    }
}

int main() {
    int n, k, raw[1000];
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> raw[i];
    }
    quicksort(raw, 0, n - 1);
    for (int i = 0; i < k; i++) {
        cout << raw[i] << " ";
    }
    return 0;
}

#if 0
int quicksort(int raw[], int s, int e) {
    if (s >= e) return 0; // POE:
    cout << "s = " << s << " e = " << e << endl;
    if (s + 1 == e) {
        if (raw[s] > raw[e]) {
            int t = raw[s];
            raw[s] = raw[e];
            raw[e] = t;
            return 0;
        }
    }
    cout << "enter quicksort" << endl;
    int pivot = raw[s];
    int i = s + 1, j = e;

    while (i < j) {
        if (raw[i] >= pivot) {
            int t = raw[j];
            raw[j] = raw[i];
            raw[i] = t;
            j--;
            cout << "ij = " << i << j << endl;
        }
        i++;
    }
    // cout << i << endl;
    raw[s] = raw[j];
    raw[j] = pivot;

    quicksort(raw, s, i - 1);
    quicksort(raw, i + 1, e);
    
    return 0;
}
#endif
// 64 位输出请用 printf("%lld")