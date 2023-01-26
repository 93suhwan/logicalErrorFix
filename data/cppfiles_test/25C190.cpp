#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string x, y;
int dp[505][505][2];
int go(int m, int i, int right) {
  if (x[m] != y[i]) return 0;
  if (i == y.size() - 1) return 1;
  int ret = dp[m][i][right];
  if (~ret) return ret;
  int c1 = 0, c2 = 0;
  if (m < x.size() - 1 && right) c1 = go(m + 1, i + 1, 1);
  if (m > 0) c2 = go(m - 1, i + 1, 0);
  return ret = max(c1, c2);
}
bool solve() {
  cin >> x >> y;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < x.size(); i++) {
    if (go(i, 0, 1)) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
