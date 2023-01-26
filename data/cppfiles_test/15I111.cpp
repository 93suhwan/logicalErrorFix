#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
const int32_t N = 500;
const int32_t MOD = 1e9 + 7;
int32_t c[N][N];
int32_t add(int32_t a, int32_t b) {
  if (a + b < MOD) return a + b;
  return a + b - MOD;
}
int32_t sub(int32_t a, int32_t b) {
  if (a - b >= 0) return a - b;
  return a - b + MOD;
}
int32_t mul(int32_t a, int32_t b) { return int64_t(a) * b % MOD; }
void calc() {
  c[0][0] = 1;
  for (int32_t n = 1; n < N; ++n) {
    c[n][0] = 1;
    for (int32_t k = 1; k <= n; ++k) {
      c[n][k] = add(c[n - 1][k - 1], c[n - 1][k]);
    }
  }
}
vector<vector<int32_t>> g;
void dfs(vector<int32_t> &cntH, int32_t v, int32_t p, int32_t h) {
  ++cntH[h];
  for (auto &u : g[v]) {
    if (u != p) dfs(cntH, u, v, h + 1);
  }
}
int32_t getC(int32_t n, int32_t k) { return c[n][k]; }
void solve() {
  int32_t n, k;
  cin >> n >> k;
  int32_t ans = 0;
  g.clear();
  g.resize(n);
  for (int32_t i = 0; i + 1 < n; ++i) {
    int32_t a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << '\n';
    return;
  }
  for (int32_t i = 0; i < n; ++i) {
    vector<int32_t> cntH(n, 0);
    dfs(cntH, i, i, 0);
    for (int32_t h = 1; h < n; ++h) {
      ans = add(ans, getC(cntH[h], k));
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  io();
  calc();
  int32_t ttt;
  std::cin >> ttt;
  while (ttt-- > 0) {
    solve();
  }
  return 0;
}
