#include <bits/stdc++.h>
using namespace std;
const int MX = 2002;
const long long MOD = 1e9 + 7;
int dp[MX][2 * MX], ct[MX][2 * MX];
void inc(int& p, long long x) { p = ((long long)p + x) % MOD; }
pair<int, int> trans(char c, int i) {
  int v0, v1;
  if (c == '?') {
    v0 = 1;
    v1 = 1;
  } else {
    v0 = (c - '0') != (i & 1);
    v1 = (c - '0') == (i & 1);
  }
  return make_pair(v0, v1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ct[0][MX] = 1;
    for (int i = 1; i <= n; i++) {
      auto [a0, a1] = trans(s[i - 1], i);
      auto [b0, b1] = trans(t[i - 1], i);
      long long um = a0 * b1;
      long long u0 = a0 * b0 + a1 * b1;
      long long u1 = a1 * b0;
      for (int j = 1; j < 2 * MX - 1; j++) {
        inc(ct[i][j], um * ct[i - 1][j + 1]);
        inc(ct[i][j], u0 * ct[i - 1][j]);
        inc(ct[i][j], u1 * ct[i - 1][j - 1]);
        inc(dp[i][j], um * dp[i - 1][j + 1]);
        inc(dp[i][j], u0 * dp[i - 1][j]);
        inc(dp[i][j], u1 * dp[i - 1][j - 1]);
        inc(dp[i][j], (long long)abs(MX - j) * ct[i][j]);
      }
    }
    cout << dp[n][MX] << '\n';
    for (int i = 0; i < n + 1; i++)
      for (int j = 0; j < 2 * n + 1; j++) {
        dp[i][MX - n + j] = 0;
        ct[i][MX - n + j] = 0;
      }
  }
}
