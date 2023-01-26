#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 2e3 + 10;
const long long mod = 1e9 + 7;
const long long base = 3e18;
long long dp[maxn][2 * maxn];
long long dp1[maxn][2 * maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    long long len = n;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= 2 * n; j++) {
        dp[i][j] = 0;
        dp1[i][j] = 0;
      }
    }
    dp[0][0 + len] = 1;
    for (long long i = 1; i <= n; i++) {
      for (int j = 0; j <= 2 * n; j++) {
        vector<long long> vt;
        vector<long long> vt1;
        if (s[i] == '?') {
          vt.push_back(1);
          vt.push_back(0);
        } else if (s[i] == '1') {
          vt.push_back(1);
        } else {
          vt.push_back(0);
        }
        if (t[i] == '?') {
          vt1.push_back(1);
          vt1.push_back(0);
        } else if (t[i] == '1') {
          vt1.push_back(1);
        } else {
          vt1.push_back(0);
        }
        for (auto to : vt) {
          for (auto to1 : vt1) {
            long long x = to;
            long long y = to1;
            if (i % 2 == 0) x = 1 - x, y = 1 - y;
            if (x == y) {
              dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
              dp1[i][j] = (dp1[i][j] + dp1[i - 1][j]) % mod;
            } else if (x) {
              if (j + 1 <= 2 * n) {
                if (j >= n) {
                  dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
                  dp1[i][j + 1] =
                      ((dp1[i][j + 1] + dp1[i - 1][j] - dp[i - 1][j] * i) %
                           mod +
                       mod) %
                      mod;
                } else {
                  dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
                  dp1[i][j + 1] =
                      ((dp1[i][j + 1] + dp1[i - 1][j] + dp[i - 1][j] * i) %
                           mod +
                       mod) %
                      mod;
                }
              }
            } else {
              if (j != 0) {
                if (j <= n) {
                  dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                  dp1[i][j - 1] =
                      ((dp1[i][j - 1] + dp1[i - 1][j] - dp[i - 1][j] * i) %
                           mod +
                       mod) %
                      mod;
                } else {
                  dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                  dp1[i][j - 1] =
                      ((dp1[i][j - 1] + dp1[i - 1][j] + dp[i - 1][j] * i) %
                           mod +
                       mod) %
                      mod;
                }
              }
            }
          }
        }
      }
    }
    cout << dp1[n][n] << "\n";
  }
}
