#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long tt, n;
pair<long long, long long> dp[2010][2010][2];
string s, t;
void add(pair<long long, long long> &x, pair<long long, long long> y) {
  (x.first += y.first) %= MOD;
  (x.second += y.second) %= MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tt;
  for (long long tn = 0; tn < tt; ++tn) {
    cin >> n >> s >> t;
    for (long long i = 0; i < n; ++i)
      if (i % 2 == 1) {
        if (s[i] == '0')
          s[i] = '1';
        else if (s[i] == '1')
          s[i] = '0';
        if (t[i] == '0')
          t[i] = '1';
        else if (t[i] == '1')
          t[i] = '0';
      }
    for (long long i = 0; i < n + 3; ++i)
      for (long long j = 0; j < n + 3; ++j)
        for (long long k = 0; k < 2; ++k) dp[i][j][k] = make_pair(0, 0);
    dp[0][0][0] = make_pair(1, 0);
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < i + 1; ++j)
        for (long long k = 0; k < 2; ++k)
          if (dp[i][j][k].first > 0 || dp[i][j][k].second > 0) {
            long long wys = dp[i][j][k].first, val = dp[i][j][k].second;
            if (k == 0) {
              if (s[i] != '1' && t[i] != '1')
                add(dp[i + 1][j][0], make_pair(wys, (val + wys * j) % MOD));
              if (s[i] != '0' && t[i] != '1')
                add(dp[i + 1][j + 1][0], make_pair(wys, (val + wys * j) % MOD));
              if (s[i] != '1' && t[i] != '0') {
                if (j == 0)
                  add(dp[i + 1][1][1], make_pair(wys, val));
                else
                  add(dp[i + 1][j - 1][0],
                      make_pair(wys, (val + wys * j) % MOD));
              }
              if (s[i] != '0' && t[i] != '0')
                add(dp[i + 1][j][0], make_pair(wys, (val + wys * j) % MOD));
            } else {
              if (s[i] != '1' && t[i] != '1')
                add(dp[i + 1][j][1], make_pair(wys, (val + wys * j) % MOD));
              if (s[i] != '1' && t[i] != '0')
                add(dp[i + 1][j + 1][1], make_pair(wys, (val + wys * j) % MOD));
              if (s[i] != '0' && t[i] != '1') {
                if (j == 1)
                  add(dp[i + 1][0][0], make_pair(wys, (val + wys * j) % MOD));
                else
                  add(dp[i + 1][j - 1][1],
                      make_pair(wys, (val + wys * j) % MOD));
              }
              if (s[i] != '0' && t[i] != '0')
                add(dp[i + 1][j][1], make_pair(wys, (val + wys * j) % MOD));
            }
          }
    cout << dp[n][0][0].second << endl;
  }
  return 0;
}
