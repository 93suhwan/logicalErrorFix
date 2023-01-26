#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void debug(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  debug(comma + 1, args...);
}
const int INF = 1000000000 + 5;
const int N = 3e3 + 5;
const int M = 30;
const long long oo = LLONG_MAX;
const int mod = 1e9 + 7;
int dp[N][N][2];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> prefLen(n);
  vector<vector<int>> num(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    prefLen[i] = (int)num[a[i]].size();
    num[a[i]].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    dp[i][i][0] = dp[i][i][1] = 0;
  }
  for (int len = 2; len <= n; ++len) {
    for (int l = 0; l + len <= n; ++l) {
      int r = l + len - 1;
      if (len == 2) {
        dp[l][r][0] = dp[l][r][1] = (a[l] != a[r]);
        continue;
      }
      dp[l][r][0] = dp[l][r][1] =
          min(dp[l + 1][r - 1][0], dp[l + 1][r - 1][1]) + 1;
      if (a[l] != a[r]) ++dp[l][r][0], ++dp[l][r][1];
      if (a[l] == a[r]) {
        for (int midId = prefLen[l] + 1; midId < (int)num[a[l]].size();
             ++midId) {
          int mid = num[a[l]][midId];
          if (mid > r) break;
          dp[l][r][0] = dp[l][r][1] =
              min(dp[l][r][0], dp[l][mid][0] + dp[mid][r][0]);
        }
      } else {
        for (int midId = prefLen[l] + 1; midId < (int)num[a[l]].size();
             ++midId) {
          int mid = num[a[l]][midId];
          if (mid > r) break;
          dp[l][r][0] = min(
              dp[l][r][0],
              dp[l][mid][0] + min(dp[mid + 1][r][0], dp[mid + 1][r][1]) + 1);
        }
        for (int midId = prefLen[r] - 1; midId >= 0; --midId) {
          int mid = num[a[r]][midId];
          if (mid < l) break;
          dp[l][r][1] = min(
              dp[l][r][1],
              dp[mid][r][0] + min(dp[l][mid - 1][0], dp[l][mid - 1][1]) + 1);
        }
      }
    }
  }
  cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
