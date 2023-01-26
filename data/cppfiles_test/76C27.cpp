#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  n = min(n, 50);
  vector<vector<int>> g(n, vector<int>(n));
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u < n and v < n) g[u][v] = g[v][u] = 1;
  }
  for (int a = 0; a < n; ++a) {
    for (int b = a + 1; b < n; ++b) {
      if (!g[a][b]) continue;
      for (int c = b + 1; c < n; ++c) {
        if (!g[a][c] or !g[b][c]) continue;
        for (int d = c + 1; d < n; ++d) {
          if (!g[a][d] or !g[b][d] or !g[c][d]) continue;
          for (int e = d + 1; e < n; ++e) {
            if (!g[a][e] or !g[b][e] or !g[c][e] or !g[d][e]) continue;
            cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << ' '
                 << e + 1;
            return 0;
          }
        }
      }
    }
  }
  for (int a = 0; a < n; ++a) {
    for (int b = a + 1; b < n; ++b) {
      if (g[a][b]) continue;
      for (int c = b + 1; c < n; ++c) {
        if (g[a][c] or g[b][c]) continue;
        for (int d = c + 1; d < n; ++d) {
          if (g[a][d] or g[b][d] or g[c][d]) continue;
          for (int e = d + 1; e < n; ++e) {
            if (g[a][e] or g[b][e] or g[c][e] or g[d][e]) continue;
            cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << ' '
                 << e + 1;
            return 0;
          }
        }
      }
    }
  }
  cout << -1;
  return 0;
}
