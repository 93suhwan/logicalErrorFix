#include <bits/stdc++.h>
using namespace std;
inline void debugMode() {}
long long dp1[1001][1001], dp2[1001][1001];
int state[1001][1001];
void solvecases(int cse) {
  long long n, m, q;
  cin >> n >> m >> q;
  long long cnt = 1ll * n * m;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp1[i][j] = dp2[i - 1][j] + 1;
      dp2[i][j] = dp1[i][j - 1] + 1;
      ans += dp1[i][j] + dp2[i][j];
    }
  }
  ++n;
  ++m;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    long long a, b;
    if (state[x][y]) {
      a = dp2[x - 1][y] + 1;
      b = dp1[x][y - 1] + 1;
      state[x][y] = 0;
      ++cnt;
      dp1[x][y] = a;
      dp2[x][y] = b;
      ans += a + b;
      if (((x) < n && (y + 1) < m && (x) >= 0 && (y + 1) >= 0) &&
          !state[x][y + 1]) {
        dp2[x][y + 1] += a;
        ans += a;
      } else
        a = 0;
    } else {
      a = -dp1[x][y];
      b = -dp2[x][y];
      state[x][y] = 1;
      --cnt;
      dp1[x][y] = dp2[x][y] = 0;
      ans += a + b;
      if (((x) < n && (y + 1) < m && (x) >= 0 && (y + 1) >= 0) &&
          !state[x][y + 1]) {
        dp2[x][y + 1] += a;
        ans += a;
      } else
        a = 0;
    }
    int j, k;
    j = x + 1;
    k = y + 1;
    while (j < n && k < m) {
      if (state[j][k - 1]) {
        b = 0;
      }
      if (state[j][k]) a = 0;
      dp1[j][k - 1] += b;
      dp1[j][k] += a;
      ans += a + b;
      if (state[j][k]) {
        b = 0;
      }
      if (((j) < n && (k + 1) < m && (j) >= 0 && (k + 1) >= 0)) {
        if (state[j][k + 1]) a = 0;
        dp2[j][k + 1] += a;
        ans += a;
      }
      dp2[j][k] += b;
      ans += b;
      ++j;
      ++k;
    }
    if (j < n) {
      if (!state[j][k - 1]) {
        dp1[j][k - 1] += b;
        ans += b;
      }
    }
    cout << ans - cnt << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solvecases(i);
  }
}
