#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long nax = 1e6 + 10, mod = 1e9 + 7, inf = 1e18;
struct node {
  vector<long long> par, sz;
  node(long long n) : par(n), sz(n) { iota(par.begin(), par.end(), 0); }
  long long find(long long v) {
    return v == par[v] ? v : par[v] = find(par[v]);
  }
  bool same(long long x, long long y) { return find(x) == find(y); }
  bool merge(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    sz[x] += sz[y];
    par[y] = x;
    return 1;
  }
  long long get(long long x) { return sz[find(x)]; }
};
void solve() {
  long long n, m;
  std::cin >> n >> m;
  std::vector<long long> v{0LL, 1LL << n};
  long long op[m];
  long long x[m], y[m];
  for (long long i = 0; i < m; i++) {
    std::string t;
    std::cin >> t;
    if (t == "block") {
      op[i] = 0;
      std::cin >> x[i] >> y[i];
      y[i]++;
      v.push_back(x[i]);
      v.push_back(y[i]);
    } else {
      op[i] = 1;
      std::cin >> x[i] >> y[i];
    }
  }
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  long long N = v.size() - 1;
  for (long long i = 0; i < N; i++) {
    long long l = v[i];
    long long r = v[i + 1] - 1;
    long long k = 0;
    while ((l >> k) != (r >> k)) {
      k++;
    }
    if (k > 0) {
      v.push_back(r & ~((1LL << (k - 1)) - 1));
    }
  }
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  N = v.size() - 1;
  node g(N);
  std::vector<long long> adj[N];
  auto add = [&](long long i, long long j, long long k) {
    long long l = std::max(v[i], v[j] - (1LL << k));
    long long r = std::min(v[i + 1], v[j + 1] - (1LL << k)) - 1;
    if ((~l >> k & 1) || (~r >> k & 1) || (l >> k) != (r >> k)) {
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
  };
  for (long long k = 0; k < n; k++) {
    long long d = 1LL << k;
    for (long long i = 0, j = 0; i < N; i++) {
      while (j < N && v[j + 1] <= v[i] + d) {
        j++;
      }
      while (j < N && v[j + 1] <= v[i + 1] + d) {
        add(i, j, k);
        j++;
      }
      if (j < N && v[j] < v[i + 1] + d) {
        add(i, j, k);
      }
    }
  }
  bool vis[N];
  std::fill(vis, vis + N, true);
  for (long long i = 0; i < m; i++) {
    if (op[i] == 0) {
      long long j = std::lower_bound(v.begin(), v.end(), x[i]) - v.begin();
      while (v[j] < y[i]) {
        vis[j++] = false;
      }
    }
  }
  for (long long i = 0; i < N; i++) {
    if (vis[i]) {
      for (auto j : adj[i]) {
        if (vis[j]) {
          g.merge(i, j);
        }
      }
    }
  }
  long long res[m];
  for (long long i = m - 1; i >= 0; i--) {
    if (op[i] == 0) {
      long long j = std::lower_bound(v.begin(), v.end(), x[i]) - v.begin();
      while (v[j] < y[i]) {
        vis[j] = true;
        for (auto k : adj[j]) {
          if (vis[k]) {
            g.merge(j, k);
          }
        }
        j++;
      }
    } else {
      long long a = std::upper_bound(v.begin(), v.end(), x[i]) - v.begin() - 1;
      long long b = std::upper_bound(v.begin(), v.end(), y[i]) - v.begin() - 1;
      res[i] = g.same(a, b);
    }
  }
  for (long long i = 0; i < m; i++) {
    if (op[i] == 1) {
      std::cout << res[i] << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt = 1;
  for (long long i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}
