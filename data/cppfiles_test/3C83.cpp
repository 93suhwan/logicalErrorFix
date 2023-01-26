#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9;
const long long NN = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
template <typename T, typename T1>
T maxn(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T minn(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string second;
  cin >> second;
  if (second[0] == '0') {
    if ((int)second.size() > 1)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
    return;
  }
  if ((int)second.size() == 1 && (second[0] == '_' || second[0] == 'X')) {
    cout << 1 << "\n";
    return;
  }
  second = "#" + second;
  long long int dp[9][25][10] = {};
  long long int xst = 0;
  if (second[1] == 'X') xst = 1;
  for (int(i) = (xst); (i) < (10); (i)++) dp[0][0][i] = 1;
  for (int(i) = (0); (i) < ((int)second.size() - 1); (i)++) {
    for (int(m) = (0); (m) < (25); (m)++) {
      for (int(d) = (xst); (d) < (10); (d)++) {
        long long int mm;
        if (second[i + 1] == 'X') {
          mm = (m * 10 + d) % 25;
          dp[i + 1][mm][d] += dp[i][m][d];
          continue;
        }
        if (second[i + 1] == '_') {
          long long int st = 0;
          if (i + 1 == 1) st = 1;
          for (int(x) = (st); (x) < (10); (x)++) {
            mm = (m * 10 + x) % 25;
            dp[i + 1][mm][d] += dp[i][m][d];
          }
          continue;
        }
        mm = (m * 10 + second[i + 1] - '0') % 25;
        dp[i + 1][mm][d] += dp[i][m][d];
      }
    }
  }
  long long int ans = 0, x = 0;
  for (auto z : second) {
    if (z == 'X') x = 1;
  }
  if (x) {
    for (int(i) = (0); (i) < (10); (i)++)
      ans += dp[(int)second.size() - 1][0][i];
  } else
    ans = dp[(int)second.size() - 1][0][9];
  cout << ans << "\n";
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int testcase = 1;
  while (testcase--) solve();
  return 0;
}
