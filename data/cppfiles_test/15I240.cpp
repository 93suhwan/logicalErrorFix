#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    vector<vector<int>> C(n + 1, vector<int>(n + 1));
    const int MOD = (int)1e9 + 7;
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      C[i][0] = C[i][i] = 1;
      for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
      }
    }
    vector<int> d(n + 1);
    vector<int> f(n + 1);
    function<void(int, int, int)> dfs = [&](int cur, int fa,
                                            int depth) -> void {
      d[cur] = depth;
      f[cur] = fa;
      for (auto nx : G[cur]) {
        if (nx == fa) {
          continue;
        }
        dfs(nx, cur, depth + 1);
      }
    };
    dfs(1, 0, 0);
    auto lca = [&](int x, int y) -> int {
      while (x != y) {
        if (d[x] < d[y]) {
          swap(x, y);
        }
        x = f[x];
      }
      return x;
    };
    vector<vector<set<int>>> cnt(n + 1, vector<set<int>>(n + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) {
          continue;
        }
        if (d[i] != d[j]) {
          continue;
        }
        int k = lca(i, j);
        cnt[k][d[i]].insert(i);
        cnt[k][d[i]].insert(j);
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        int have = cnt[i][j].size();
        if (2 * d[i] - j >= 0) {
          have += 1;
        }
        ans = (ans + C[have][k]) % MOD;
      }
    }
    if (k == 2) {
      ans = (ans + n - 1) % MOD;
    }
    cout << ans << "\n";
  }
  return 0;
}
