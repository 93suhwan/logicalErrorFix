#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(48, vector<int>(48));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    if (u < 48 && v < 48) {
      adj[u][v] = 1;
      adj[v][u] = 1;
    }
  }
  for (int i = 0; i < min(48, n); ++i) {
    for (int j = i + 1; j < min(48, n); ++j) {
      if (adj[i][j] == 0) continue;
      for (int p = j + 1; p < min(48, n); ++p) {
        if (adj[i][p] == 0 || adj[j][p] == 0) continue;
        for (int q = p + 1; q < min(48, n); ++q) {
          if (adj[i][q] == 0 || adj[j][q] == 0 || adj[p][q] == 0) continue;
          for (int r = q + 1; r < min(48, n); ++r) {
            if (adj[i][r] == 0 || adj[j][r] == 0 || adj[p][r] == 0 ||
                adj[q][r] == 0)
              continue;
            cout << i + 1 << ' ' << j + 1 << ' ' << p + 1 << ' ' << q + 1 << ' '
                 << r + 1;
            return 0;
          }
        }
      }
    }
  }
  for (int i = 0; i < min(48, n); ++i) {
    for (int j = i + 1; j < min(48, n); ++j) {
      if (adj[i][j] == 1) continue;
      for (int p = j + 1; p < min(48, n); ++p) {
        if (adj[i][p] == 1 || adj[j][p] == 1) continue;
        for (int q = p + 1; q < min(48, n); ++q) {
          if (adj[i][q] == 1 || adj[j][q] == 1 || adj[p][q] == 1) continue;
          for (int r = q + 1; r < min(48, n); ++r) {
            if (adj[i][r] == 1 || adj[j][r] == 1 || adj[p][r] == 1 ||
                adj[q][r] == 1)
              continue;
            cout << i + 1 << ' ' << j + 1 << ' ' << p + 1 << ' ' << q + 1 << ' '
                 << r + 1;
            return 0;
          }
        }
      }
    }
  }
  cout << -1;
}
