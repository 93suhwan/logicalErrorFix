#include <bits/stdc++.h>
using namespace std;
const int up = 3e3 + 3;
int a[up], dp[up][up];
vector<vector<int>> pos;
int solve(int l, int r) {
  if (dp[l][r] != 1000000000) return dp[l][r];
  for (int i : pos[a[l]]) {
    if (i >= l && i <= r) {
      if (i > l) dp[l][r] = min(dp[l][r], solve(l, i - 1) + solve(i, r));
      if (i < r) dp[l][r] = min(dp[l][r], solve(l, i) + solve(i + 1, r) + 1);
    }
  }
  if (a[l] == a[r]) {
    int ln = l, rn = r;
    while (ln < rn && a[ln + 1] == a[ln]) ++ln;
    while (rn > ln && a[rn - 1] == a[rn]) --rn;
    if (ln + 1 <= rn - 1)
      dp[l][r] = min(dp[l][r], solve(ln + 1, rn - 1) + 1);
    else
      dp[l][r] = 0;
  }
  return dp[l][r];
}
void init(int n) {
  pos.resize(n + 1);
  for (int i = 0; i <= n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      dp[i][j] = 1000000000;
    }
    pos.clear();
  }
}
void solve() {
  int n;
  cin >> n;
  init(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  cout << solve(0, n - 1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
