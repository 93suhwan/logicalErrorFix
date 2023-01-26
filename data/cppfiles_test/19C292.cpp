#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int t, dp[15][N * 20], n, a[N];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  int MX = 1e6;
  while (t--) {
    cin >> n;
    int first = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < (1 << n); i++) {
      int sum = 0;
      vector<int> x, y;
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i) {
          x.push_back(j);
        } else
          y.push_back(j);
      }
      int cnt = x.size();
      for (int j = 0; j < (1 << cnt); j++) {
        int sum = 0;
        for (int k = 0; k < cnt; k++) {
          if ((1 << k) & j) {
            sum += a[x[k]];
          } else
            sum -= a[x[k]];
        }
        for (int k = 0; k < y.size(); k++) {
          dp[y[k]][sum + MX]++;
        }
        if (sum == 0 && i) first = 1;
      }
    }
    a[n] = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i][a[i] + MX] > 1 || dp[i][-a[i] + MX] > 1) first = 1;
    }
    for (int i = 0; i <= 2 * MX; i++)
      for (int j = 0; j <= n; j++) dp[j][i] = 0;
    if (first)
      cout << "YES"
           << " ";
    else
      cout << "NO"
           << " ";
  }
}
