#include <bits/stdc++.h>
using namespace std;
int dp[2021];
int main() {
  ios_base::sync_with_stdio(false);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      for (int j = n; j > 0; --j) {
        if (dp[j - 1] != -1) {
          dp[j] = max(dp[j], dp[j - 1] += (x == j));
        }
      }
    }
    int f = -1;
    for (int i = n; i >= 1; i--) {
      if (dp[i] >= k) {
        cout << n - i << endl;
        break;
      }
    }
    if (f) cout << f << endl;
  }
}
