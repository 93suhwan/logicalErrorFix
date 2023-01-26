#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,tune=native")
template <typename T>
using Prior = std::priority_queue<T>;
template <typename T>
using prior = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using namespace std;
const long long md = 1e9 + 7;
inline long long mod(long long x) { return (x % md + md) % md; }
long long qpow(long long base, long long pow) {
  long long ret = 1;
  for (; pow; pow >>= 1, base = mod(base * base))
    if (pow & 1) ret = mod(ret * base);
  return ret;
}
vector<long long> fac(101, 1), invfac(101, 1);
void pre() {
  for (int i = 2; i < 101; ++i) fac[i] = mod(i * fac[i - 1]);
  invfac[100] = qpow(fac[100], md - 2);
  for (int i = 100; i; --i) invfac[i - 1] = mod(invfac[i] * i);
}
inline long long C(long long x, long long y) {
  assert(x >= y);
  return mod(fac[x] * mod(invfac[y] * invfac[x - y]));
}
int n, k;
vector<long long> bfs(const vector<vector<long long>>& g, int x) {
  vector<long long> ret(n, -1);
  vector<bool> visit(n);
  queue<pair<long long, long long>> q;
  q.push({x, 0});
  while (q.size()) {
    auto top = q.front();
    q.pop();
    visit[top.first] = true;
    ret[top.first] = top.second;
    for (auto nei : g[top.first])
      if (!visit[nei]) q.push({nei, top.second + 1});
  }
  return ret;
}
void solve() {
  cin >> n >> k;
  vector<vector<long long>> g(n);
  for (auto [u, v] : vector<pair<long long, long long>>(n - 1)) {
    cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  };
  ;
  if (k == 2) return cout << C(n, k) << '\n', void();
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    vector<long long> dis = bfs(g, i);
    vector<long long> cnt(n);
    for (auto x : dis) ++cnt[x];
    assert(cnt[0] == 1);
    for (int j = 0; j < n; ++j)
      if (cnt[j] >= k) ans = mod(C(cnt[j], k) + ans);
  }
  return cout << ans << '\n', void();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int _ = 1;
  pre();
  cin >> _;
  vector<long long> __(_);
  iota(begin(__), end(__), 1);
  for (auto i : __) {
    solve();
  }
  return 0;
}
