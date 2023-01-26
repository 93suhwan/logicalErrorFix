#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
  string s;
  cin >> s;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (i == n - 1 && j == n - 1) continue;
      if (s[i] == s[j])
        lcp[i][j] = lcp[i + 1][j + 1] + 1;
      else
        lcp[i][j] = 0;
    }
  }
  vector<int> res(n, 0);
  res[0] = n;
  int ans = res[0];
  for (int i = 1; i < n; ++i) {
    res[i] = n - i;
    for (int j = 0; j < i; ++j) {
      if (i + lcp[i][j] < n && s[i + lcp[i][j]] >= s[j + lcp[i][j]]) {
        res[i] = max(res[i], res[j] + n - i - lcp[i][j]);
      }
    }
    ans = max(ans, res[i]);
  }
  cout << ans << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
