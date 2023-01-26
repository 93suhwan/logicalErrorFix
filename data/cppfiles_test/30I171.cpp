#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e6 + 7;
struct DSU {
  vector<int> f;
  void init(int n) {
    f.resize(n + 1);
    iota(f.begin(), f.end(), 0);
  }
  int seek(int x) { return x == f[x] ? x : (f[x] = seek(f[x])); }
  bool same(int u, int v) { return seek(u) == seek(v); }
  void Merge(int u, int v) { f[seek(u)] = seek(v); }
} dsu;
vector<int> prime[maxn];
set<pair<int, int> > onepath;
void solve() {
  dsu.init(maxn);
  int n, m, mx = 0;
  scanf("%d %d", &n, &m);
  vector<int> vec(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &vec[i]);
    mx = max(mx, vec[i]);
  }
  for (int i = 2; i <= mx + 1; ++i) {
    if (!prime[i].size()) {
      for (int j = i; j <= mx + 1; j += i) {
        prime[j].push_back(i);
      }
    }
  }
  for (int i = 1; i <= mx + 1; ++i) {
    for (auto fac : prime[i]) {
      dsu.Merge(i, fac);
    }
  }
  for (int i = 1; i <= n; ++i) {
    vector<int> has = prime[vec[i] + 1];
    has.push_back(vec[i]);
    for (int i = 0; i < has.size(); ++i) {
      for (int j = i + 1; j < has.size(); ++j) {
        int u = has[i], v = has[j];
        u = dsu.seek(u), v = dsu.seek(v);
        if (!dsu.same(u, v)) {
          if (u > v) swap(u, v);
          onepath.insert({u, v});
        }
      }
    }
  }
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u = vec[u], v = vec[v];
    u = dsu.seek(u), v = dsu.seek(v);
    if (u > v) swap(u, v);
    if (u == v)
      puts("0");
    else if (onepath.count({u, v}))
      puts("1");
    else
      puts("2");
  }
}
int main() {
  solve();
  return 0;
}
