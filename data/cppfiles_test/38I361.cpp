#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
int n, m, q;
int T[4 * maxn];
void upd(int idx, int val, int l, int r, int nd) {
  if (l == r) {
    T[nd] = val;
    return;
  }
  if (idx <= (l + r) / 2)
    upd(idx, val, l, (l + r) / 2, nd * 2);
  else
    upd(idx, val, (l + r) / 2 + 1, r, nd * 2 + 1);
  T[nd] = max(T[nd * 2], T[nd * 2 + 1]);
}
int tap(int a, int b, int l, int r, int nd) {
  if (r < a or l > b) return 0;
  if (l >= a and r <= b) return T[nd];
  return max(tap(a, b, l, (l + r) / 2, nd * 2),
             tap(a, b, (l + r) / 2 + 1, r, nd * 2 + 1));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<vector<char>> c(n + 1, vector<char>(m + 1));
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'X') continue;
      if (i == 1 or j == 1) {
        dp[i][j] = 1;
        continue;
      }
      dp[i][j] = j;
      if (c[i - 1][j] == '.') dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      if (c[i][j - 1] == '.') dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
  }
  for (int i = 1; i <= m; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) mx = max(mx, dp[j][i]);
    upd(i, mx, 1, n, 1);
  }
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int mx = tap(x, y, 1, n, 1);
    if (mx <= x)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
