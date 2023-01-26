#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename T>
struct fenwick {
  vector<T> a;
  int n;
  fenwick(int n) : n(n), a(n) {}
  void add(int x, T v) {
    assert(0 <= x && x < n);
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] += v;
      if (a[i - 1] >= mod) a[i - 1] -= mod;
    }
  }
  T qry(int x) {
    T ret = 0;
    for (int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
    return ret % mod;
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  ++k;
  vector<vector<pair<int, int>>> g(n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  int rt = -1, res = n;
  vector<int> mx(n), sz(n), vis(n);
  function<void(int, int)> dfs = [&](int u, int fa) {
    sz[u] = 1, mx[u] = 0;
    for (auto [v, w] : g[u]) {
      if (v == fa || vis[v]) continue;
      dfs(v, u);
      sz[u] += sz[v];
      mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], res - sz[u]);
    if (rt == -1 || mx[u] < mx[rt]) rt = u;
  };
  long long ans = 0;
  for (int i = 0; i < n; ++i) ans += a[i];
  function<void(int)> dfs2 = [&](int u) {
    int pre = res;
    vis[u] = 1;
    fenwick<long long> fen(res);
    fenwick<int> fen2(res);
    vector<vector<long long>> mp1(2, vector<long long>(res));
    vector<vector<int>> mp2(2, vector<int>(res));
    function<void(int, int, int, int, int, long long)> dfs3 =
        [&](int u, int fa, int pre, int cnt, int first, long long sum) {
          if (cnt > k) return;
          sum += a[u];
          if (sum >= mod) sum -= mod;
          mp1[first][cnt] += sum;
          if (mp1[first][cnt] >= mod) mp1[first][cnt] -= mod;
          mp2[first][cnt] += 1;
          fen.add(cnt, sum);
          fen2.add(cnt, 1);
          for (auto [v, w] : g[u]) {
            if (v == fa || vis[v]) continue;
            dfs3(v, u, w, cnt + (w != pre), first, sum);
          }
        };
    function<void(int, int, int, int, int, long long)> dfs4 =
        [&](int u, int fa, int pre, int cnt, int first, long long sum) {
          if (cnt > k) return;
          sum += a[u];
          if (sum >= mod) sum -= mod;
          ans += fen.qry(k - cnt) + fen2.qry(k - cnt) * sum % mod;
          if (k + 1 - cnt < res) {
            ans +=
                mp1[first][k + 1 - cnt] + mp2[first][k + 1 - cnt] * sum % mod;
          }
          for (auto [v, w] : g[u]) {
            if (v == fa || vis[v]) continue;
            dfs4(v, u, w, cnt + (w != pre), first, sum);
          }
        };
    fen.add(0, a[u]);
    fen2.add(0, 1);
    for (auto [v, w] : g[u]) {
      if (vis[v]) continue;
      dfs4(v, u, w, 1, w, 0);
      dfs3(v, u, w, 1, w, a[u]);
    }
    for (auto [v, w] : g[u]) {
      if (vis[v]) continue;
      res = sz[v] < sz[u] ? sz[v] : pre - sz[u];
      rt = -1;
      dfs(v, u);
      dfs2(rt);
    }
    res = pre;
  };
  rt = -1;
  dfs(0, -1);
  dfs2(rt);
  cout << ans % mod << '\n';
}
