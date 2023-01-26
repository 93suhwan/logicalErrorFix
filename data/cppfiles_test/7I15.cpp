#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  vector<int> fail(m + 1);
  fail[0] = fail[1] = 0;
  for (int i = 1; i < m; i++) {
    int j = fail[i];
    while (j && b[i] != b[j]) j = fail[j];
    fail[i + 1] = b[i] == b[j] ? j + 1 : 0;
  }
  vector<vector<int>> quick_f(m + 1, vector<int>(2));
  if (b[0] == '0')
    quick_f[0][0] = 1;
  else
    quick_f[0][1] = 1;
  for (int i = 1, j; i <= m; i++) {
    j = fail[i];
    while (j && '0' != b[j]) j = fail[j];
    quick_f[i][0] = '0' == b[j] ? j + 1 : j;
    j = fail[i];
    while (j && '1' != b[j]) j = fail[j];
    quick_f[i][1] = '1' == b[j] ? j + 1 : j;
  }
  auto update_min = [](int &x, int y) {
    if (y == -1) return;
    if (x == -1 || y < x) x = y;
  };
  vector<vector<int>> f(n - m + 3, vector<int>(m + 1, -1));
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> g(n - m + 3, vector<int>(m + 1, -1));
    for (int j = 0; j <= n - m + 2; j++) {
      for (int k = 0; k <= m; k++) {
        if (f[j][k] == -1) continue;
        int tk, cost;
        if (k == m)
          tk = fail[k];
        else
          tk = k;
        cost = a[i] == b[tk] ? 0 : 1;
        tk++;
        if (tk == m) {
          update_min(g[j + 1][tk], f[j][k] + cost);
        } else {
          update_min(g[j][tk], f[j][k] + cost);
        }
        tk--;
        cost = a[i] == b[tk] ? 1 : 0;
        int idx = b[tk] - '0';
        int nk = fail[tk];
        nk = quick_f[nk][1 - idx];
        if (nk == m) {
          update_min(g[j + 1][nk], f[j][k] + cost);
        } else {
          update_min(g[j][nk], f[j][k] + cost);
        }
      }
    }
    f = g;
  }
  for (int i = 0; i <= n - m + 2; i++) {
    int v = -1;
    for (int j = 0; j <= m; j++) update_min(v, f[i][j]);
    cout << v << " \n"[i == n - m + 2];
  }
}
