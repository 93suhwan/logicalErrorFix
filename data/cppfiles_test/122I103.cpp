#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)(2e5);
int n, m;
int from[MAXN * 2], to[MAXN * 2], val[MAXN * 2];
vector<vector<int>> g;
int col[MAXN];
bool dfs(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) {
      continue;
    }
    if (col[v] == -1) {
      col[v] = col[u] ^ 1;
      if (!dfs(v, u)) {
        return false;
      }
    } else {
      if (col[v] != (col[u] ^ 1)) {
        return false;
      }
    }
  }
  return true;
}
bool check() {
  memset(col, 0xff, sizeof(col));
  for (int i = 0; i < n * 2; ++i) {
    if (col[i] == -1) {
      col[i] = 0;
      if (!dfs(i, -1)) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(12);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    g.resize(n * 2);
    for (int i = 0; i < n * 2; ++i) {
      g[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      g[i * 2].push_back(i * 2 + 1);
      g[i * 2 + 1].push_back(i * 2);
    }
    for (int i = 0; i < n - 1 + m; ++i) {
      cin >> from[i] >> to[i] >> val[i];
      --from[i];
      --to[i];
      if (val[i] != -1) {
        if (__builtin_popcount(val[i]) & 1) {
          g[from[i] * 2].push_back(to[i] * 2);
          g[to[i] * 2].push_back(from[i] * 2);
          g[from[i] * 2 + 1].push_back(to[i] * 2 + 1);
          g[to[i] * 2 + 1].push_back(from[i] * 2 + 1);
        } else {
          g[from[i] * 2].push_back(to[i] * 2 + 1);
          g[to[i] * 2 + 1].push_back(from[i] * 2);
          g[from[i] * 2 + 1].push_back(to[i] * 2);
          g[to[i] * 2].push_back(from[i] * 2 + 1);
        }
      }
    }
    if (!check()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n - 1; ++i) {
        if (val[i] == -1) {
          val[i] = col[from[i] * 2] ^ col[to[i] * 2];
        }
        cout << from[i] + 1 << " " << to[i] + 1 << " " << val[i] << endl;
      }
    }
  }
  return 0;
}
