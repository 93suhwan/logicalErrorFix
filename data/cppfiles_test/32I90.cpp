#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 100005;
long long a[M];
long long dp[M], dpp[M], cum[M];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    memset((dp), 0, sizeof(dp));
    memset((dpp), 0, sizeof(dpp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      dp[i] = a[i];
      cum[i] = cum[i - 1] + a[i];
    }
    int sq = sqrt(n);
    for (int k = 2; k <= sq + 5; k++) {
      long long mx = -1e18, sum = 0;
      int ptr = n;
      bool flg = 0;
      for (int i = n; i >= 1; i--) {
        sum += a[i];
        if ((ptr - i + 1) > k) {
          mx = max(mx, dp[ptr]);
          sum -= a[ptr];
          ptr--;
        }
        if ((ptr - i + 1) == k) {
          for (int j = ptr + 1; j + (k - 1) - 1 <= n; j++) {
            if (cum[j + k - 2] - cum[j - 1] > sum && dp[j] > sum) {
              flg = 1;
            }
          }
          dp[i] = sum;
        } else {
          dpp[i] = -1e18;
        }
      }
      if (!flg) {
        cout << k - 1 << "\n";
        break;
      }
      for (int i = 1; i <= n; i++) {
        dp[i] = dpp[i];
      }
    }
  }
  return 0;
}
