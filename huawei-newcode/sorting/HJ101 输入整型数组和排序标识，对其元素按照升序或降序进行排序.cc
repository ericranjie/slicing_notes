#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int> *v, int s, int e, int d) {

    if (s < e) {
        int p = (*v)[e]; // pivot
        int c = s - 1;
        for (int i = s; i < e; i++) {
            if ((d == 0 && (*v)[i] <= p) || // ascend
                (d == 1 && (*v)[i] >= p)) { // descend
                ++c;
                int t = (*v)[c];
                (*v)[c] = (*v)[i];
                (*v)[i] = t;
            }
        }
        (*v)[e] = (*v)[c + 1];
        (*v)[c + 1] = p;
        quicksort(v, s, c, d); // POE: not c - 1
        quicksort(v, c + 2, e, d); // POE: not c + 1
    }

    return;
}

int main() {
    int n;
    vector<int> v;
    int d;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
        // cout << v[i] << endl;
    }
    cin >> d;

    quicksort(&v, 0, v.size() - 1, d);

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
// 64 位输出请用 printf("%lld")