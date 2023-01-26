#include <bits/stdc++.h>
using namespace std;
void db() { cout << endl; }
template <typename T, typename... U>
void db(T a, U... b) {
  cout << a << ' ', db(b...);
}
const int N = 2001, inf = 2001;
void solve() {
  int n;
  cin >> n;
  int dp[n + 1][N];
  for (int &i : dp[0]) i = inf;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int l;
    cin >> l;
    for (int &j : dp[i]) j = inf;
    for (int j = 0; j < N; j++) {
      if (j + l >= dp[i - 1][j])
        dp[i][0] = min(dp[i][0], j + l);
      else {
        int &tmp = dp[i][min(j + l, dp[i - 1][j] - (j + l))];
        tmp = min(tmp, dp[i - 1][j]);
      }
      if (j - l < 0)
        dp[i][0] = min(dp[i][0], dp[i - 1][j] + l - j);
      else
        dp[i][j - l] = min(dp[i][j - l], dp[i - 1][j]);
    }
  }
  int ans = inf;
  for (int i : dp[n]) ans = min(ans, i);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
