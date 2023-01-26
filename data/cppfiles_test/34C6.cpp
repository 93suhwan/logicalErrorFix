#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> e(8192);
  for (int i = 0; i < 8192; i++) e[i].push_back(0);
  vector<int> dp(8192, 8192);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (auto j : e[a[i]]) {
      int p = dp[j ^ a[i]];
      if (p > a[i]) {
        dp[j ^ a[i]] = a[i];
        for (int k = a[i] + 1; k < p; k++) e[k].push_back(j ^ a[i]);
      }
    }
    e[a[i]].clear();
  }
  vector<int> res;
  for (int i = 0; i < 8192; i++) {
    if (dp[i] != 8192) res.push_back(i);
  }
  cout << res.size() << '\n';
  for (auto i : res) {
    cout << i << ' ';
  }
  cout << '\n';
}
