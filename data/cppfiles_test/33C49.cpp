#include <bits/stdc++.h>
using namespace std;
void solve() {
  int mx = 500 + 1, mxor = 512;
  int n;
  cin >> n;
  vector<int> v(n + 1);
  vector<vector<int>> idx(mx);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    idx[v[i]].push_back(i);
  }
  vector<int> mi(mxor, n + 1);
  mi[0] = 0;
  vector<vector<int>> dp(mx, vector<int>(mxor, n + 1));
  dp[0][0] = 0;
  for (int i = 1; i < mx; ++i) {
    for (int j = 0; j < mxor; ++j) {
      int c = i ^ j;
      int z = mi[c];
      auto nx = lower_bound(idx[i].begin(), idx[i].end(), z + 1);
      if (nx != idx[i].end()) {
        dp[i][j] = *nx;
      }
    }
    for (int j = 0; j < mxor; ++j) {
      mi[j] = min(mi[j], dp[i][j]);
    }
  }
  vector<int> a;
  for (int j = 0; j < mxor; ++j) {
    for (int i = 0; i < mx; ++i) {
      if (dp[i][j] <= n) {
        a.push_back(j);
        break;
      }
    }
  }
  cout << a.size() << endl;
  for (auto x : a) {
    cout << x << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
