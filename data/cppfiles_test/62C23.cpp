#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long infinity = 1000000000000000000;
const int inf = 1e9 + 5;
const int maxn = 1005;
int n, m, q;
int state[maxn][maxn] = {0};
long long dp[maxn][maxn][2] = {0};
long long ans = 0;
int in(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) {
    return 1;
  }
  return 0;
}
void g(int x, int y) {
  if (in(x + 1, y)) {
    ans -= dp[x][y][1];
    int extra = state[x + 1][y];
    dp[x][y][1] = extra + dp[x + 1][y][0];
    ans += dp[x][y][1];
  }
  if (in(x, y + 1)) {
    ans -= dp[x][y][0];
    int extra = state[x][y + 1];
    dp[x][y][0] = extra + dp[x][y + 1][1];
    ans += dp[x][y][0];
  }
}
void f(int x, int y) {
  if (!in(x, y)) {
    return;
  }
  if (!state[x][y]) {
    return;
  }
  g(x, y);
  if (in(x - 1, y) && state[x - 1][y]) {
    g(x - 1, y);
  }
  if (in(x, y - 1) && state[x][y - 1]) {
    g(x, y - 1);
  }
  f(x - 1, y - 1);
}
void solve() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      state[i][j] = 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      g(i, j);
      ans++;
    }
  }
  for (int Q = 0; Q < q; Q++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    state[x][y] ^= 1;
    if (!state[x][y]) {
      ans -= dp[x][y][0];
      ans -= dp[x][y][1];
      dp[x][y][0] = 0;
      dp[x][y][1] = 0;
      if (in(x - 1, y) && state[x - 1][y]) {
        g(x - 1, y);
      }
      if (in(x, y - 1) && state[x][y - 1]) {
        g(x, y - 1);
      }
      ans--;
      f(x - 1, y - 1);
    } else {
      ans++;
      f(x, y);
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC = 1;
  for (int tc = 1; tc <= TC; tc++) {
    solve();
  }
  return 0;
}
