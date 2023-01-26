#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, a[100009], dp[2007][2007];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      for (int j = 0; j <= i; j++) {
        if (j != 0)
          dp[i][j] = dp[i - 1][j] + (a[i] == i ? 1 : 0);
        else
          dp[i][j] =
              max(dp[i - 1][j - 1], dp[i - 1][j] + (a[i] == (i - j) ? 1 : 0));
      }
    }
    int res = -1;
    for (int i = 0; i <= n; i++) {
      if (dp[n][i] >= k) {
        res = i;
        break;
      }
    }
    cout << res << endl;
  }
}
