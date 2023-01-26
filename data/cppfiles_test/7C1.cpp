#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string t;
  cin >> t;
  const int inf = 1e9;
  vector<vector<int>> dp(m, vector<int>(n - m + 2, inf));
  vector<int> p = prefix_function(t);
  vector<vector<int>> jump(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      int pos = i;
      while (pos > 0 && t[pos] - '0' != j) {
        pos = p[pos - 1];
      }
      if (t[pos] - '0' == j)
        jump[i][j] = pos + 1;
      else
        jump[i][j] = 0;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> ndp(m, vector<int>(n - m + 2, inf));
    swap(dp, ndp);
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n - m + 2; k++) {
        if (ndp[j][k] == inf) continue;
        auto modify = [&](int i, int j, int c, int change) {
          int jj = jump[j][c];
          int kk = k;
          if (jj == m) jj = p[jj - 1], kk++;
          dp[jj][kk] = min(dp[jj][kk], ndp[j][k] + change);
        };
        modify(i, j, s[i] - '0', 0);
        modify(i, j, (s[i] - '0') ^ 1, 1);
      }
    }
  }
  for (int i = 0; i < n - m + 2; i++) {
    int ans = inf;
    for (int j = 0; j < m; j++) {
      ans = min(ans, dp[j][i]);
    }
    if (ans == inf) ans = -1;
    cout << ans << " ";
  }
}
