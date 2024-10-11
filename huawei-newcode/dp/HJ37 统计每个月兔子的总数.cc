#include <iostream>
#include <unistd.h>
using namespace std;

// dp-solution: guess-right ==|||
int main(int argc, char *argv[]) {
  int n, res = 0, act[32] = {0}, dp[32] = {0};
  cin >> n;

  dp[0] = dp[1] = 1;
  act[0] = act[1] = 0;
  for (int i = 0; i < n; i++) {
    if (i >= 2) {
      act[i] = dp[i - 2];
        dp[i] = dp[i - 1] + act[i];
      }
  }

  cout << dp[n - 1] << endl;

  return 0;
}