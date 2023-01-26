#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long q;
  cin >> q;
  string a;
  cin >> a;
  long long dp[n + 1][4];
  memset(dp, 0, sizeof(dp));
  for (long long i = 0; i < n; i++) {
    dp[i + 1][0] = dp[i][0];
    dp[i + 1][1] = dp[i][1];
    dp[i + 1][2] = dp[i][2];
    dp[i + 1][3] = dp[i][3];
    if (i % 2 == 0) {
      if (a[i] == '+') {
        dp[i + 1][0]++;
      } else {
        dp[i + 1][1]++;
      }
    } else {
      if (a[i] == '+') {
        dp[i + 1][2]++;
      } else {
        dp[i + 1][3]++;
      }
    }
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    long long a = dp[y][0] - dp[x - 1][0];
    long long b = dp[y][1] - dp[x - 1][1];
    long long c = dp[y][2] - dp[x - 1][2];
    long long d = dp[y][3] - dp[x - 1][3];
    long long l = y - x + 1;
    if (l % 2 == 0) {
      if (a + d == b + c)
        cout << 0 << endl;
      else
        cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
