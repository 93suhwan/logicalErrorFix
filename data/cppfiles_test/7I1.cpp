#include <bits/stdc++.h>
const int N = 505;
using namespace std;
int n;
int m;
int a[N];
int b[N];
int p[N];
int f[N][2];
int d[N][N];
int d2[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  for (int i = 1; i <= m; i++) {
    char c;
    cin >> c;
    b[i] = c - '0';
    p[i] = p[i - 1];
    while (p[i] > 0 && b[p[i] + 1] != b[i]) {
      p[i] = p[p[i] - 1];
    }
    if (b[p[i] + 1] == b[i] && i > 1) {
      p[i] += 1;
    }
    for (int x = 0; x < 2; x++) {
      if (x == b[i]) {
        f[i][x] = i + 1;
      } else if (x != b[i]) {
        f[i][x] = max(1, f[p[i - 1] + 1][x]);
      }
    }
  }
  f[m + 1][0] = f[p[m] + 1][0];
  f[m + 1][1] = f[p[m] + 1][1];
  for (int i = 1; i <= m + 1; i++) {
  }
  int inf = 1e9;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      d[i][j] = d2[i][j] = inf;
    }
  }
  d[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m + 1; j++) {
      for (int h = 0; h <= n; h++) {
        for (int x = 0; x < 2; x++) {
          d2[f[j][x]][(f[j][x] == m + 1) + h] =
              min(d2[f[j][x]][(f[j][x] == m + 1) + h], d[j][h] + (x ^ a[i]));
        }
      }
    }
    for (int j = 0; j < N; j++) {
      for (int h = 0; h < N; h++) {
        d[j][h] = d2[j][h];
        d2[j][h] = inf;
      }
    }
  }
  for (int i = 0; i <= n - m + 1; i++) {
    int res = inf;
    for (int j = 1; j <= m + 1; j++) {
      res = min(res, d[j][i]);
    }
    if (res == inf) {
      res = -1;
    }
    cout << res << " ";
  }
}
