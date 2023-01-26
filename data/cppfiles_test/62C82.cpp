#include <bits/stdc++.h>
using namespace std;
const long long N = 1000 + 10, M = 998244353;
int t;
int n, m, q;
bool locked[N][N];
long long num[N][N][2];
long long ans = 0;
int calc(int i, int j, int t) {
  if (i > n || j > m) return 0;
  if (num[i][j][t] != 0) return num[i][j][t];
  num[i][j][t] = 1;
  if (t == 0)
    num[i][j][t] += calc(i + 1, j, t ^ 1);
  else
    num[i][j][t] += calc(i, j + 1, t ^ 1);
  return num[i][j][t];
}
void go(int i, int j, int t, int val) {
  if (i <= 0 || j <= 0 || locked[i][j]) return;
  if (t == 0) {
    num[i][j][t] -= val;
    ans -= val;
    return go(i, j - 1, t ^ 1, val);
  } else {
    num[i][j][t] -= val;
    ans -= val;
    return go(i - 1, j, t ^ 1, val);
  }
}
void go2(int i, int j, int t) {
  num[i][j][t] = 1;
  ans++;
  if (t == 0) {
    if (i < n) {
      num[i][j][t] += num[i + 1][j][t ^ 1];
      ans += num[i + 1][j][t ^ 1];
    }
  } else {
    if (j < m) {
      num[i][j][t] += num[i][j + 1][t ^ 1];
      ans += num[i][j + 1][t ^ 1];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 2; k++) ans += calc(i, j, k);
    }
  }
  long long free = n * m;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (!locked[x][y]) {
      go(x, y, 0, num[x][y][0]);
      go(x, y, 1, num[x][y][1]);
      locked[x][y] = 1;
      free--;
    } else {
      go2(x, y, 0);
      go2(x, y, 1);
      locked[x][y] = 0;
      go(x, y, 0, -num[x][y][0]);
      go(x, y, 1, -num[x][y][1]);
      num[x][y][0] /= 2;
      num[x][y][1] /= 2;
      ans -= num[x][y][0] + num[x][y][1];
      free++;
    }
    cout << ans - free << "\n";
  }
  return 0;
}
