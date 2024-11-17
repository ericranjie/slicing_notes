#include <iostream>
#include <unistd.h>
using namespace std;

// need-reveal: comfuse;
int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    int col = n, cur = 1, row_start_step = 2,
      row_step = row_start_step, col_start_step = 1,
      col_step = col_start_step, row_cur = cur,
      col_cur = cur;
    for (int i = 0; i < n; i++) { // column step:
        for (int j = 0; j < col; j++) { // row step:
            cout << row_cur << " ";
            row_cur += row_step;
            row_step += 1;
        }
        cout << endl;
        col_cur += col_step;
        col_step += 1;
        row_cur = col_cur;

        row_start_step += 1; // POE:
        row_step = row_start_step;

        col--; // POE:
    }

    return 0;
}