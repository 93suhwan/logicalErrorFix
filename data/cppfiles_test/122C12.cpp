#include <bits/stdc++.h>
using namespace std;
const long long INF = INT_MAX;
const long long LNF = INF * INF;
const long long MOD = 1000000007;
const long long mod = 998244353;
const long double eps = 1e-12;
const long long MAX = 200010;
long long n, m;
vector<pair<long long, long long> > edge[MAX];
vector<long long> et[MAX];
long long pref[MAX];
long long dif[MAX];
long long res[MAX];
long long tu[MAX], tv[MAX], tp[MAX];
long long dep[MAX];
bool vis[MAX];
void dfsd(long long v, long long pv) {
  dep[v] = dep[pv] + 1;
  for (long long i : et[v]) {
    if (i == pv) continue;
    dfsd(i, v);
  }
}
void dfst(long long v, long long pv) {
  for (long long i : et[v]) {
    if (i == pv) continue;
    if (res[i] == -1) res[i] = pref[i] ^ pref[v];
    dfst(i, v);
  }
}
void dfs(long long v) {
  vis[v] = 1;
  for (pair<long long, long long> e : edge[v]) {
    long long u = e.first, p = e.second;
    if (!vis[u]) {
      pref[u] = pref[v] ^ p;
      dfs(u);
    }
  }
}
bool check_bi() {
  for (long long i = (1); i <= (n); i += (1)) {
    if (!vis[i]) dfs(i);
  }
  for (long long v = (1); v <= (n); v += (1)) {
    for (pair<long long, long long> e : edge[v]) {
      long long u = e.first, p = e.second;
      if ((pref[v] ^ p) != pref[u]) return 0;
    }
  }
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (long long i = (1); i <= (n); i += (1)) {
      pref[i] = dif[i] = vis[i] = 0;
      edge[i].clear();
      et[i].clear();
      res[i] = -1;
    }
    for (long long i = (1); i <= (n - 1); i += (1)) {
      long long u, v, p;
      cin >> u >> v >> p;
      tu[i] = u, tv[i] = v, tp[i] = p;
      et[u].push_back(v);
      et[v].push_back(u);
      if (p != -1) {
        p = __builtin_popcount(p) % 2;
        edge[u].emplace_back(v, p);
        edge[v].emplace_back(u, p);
      }
    }
    for (long long i = (1); i <= (m); i += (1)) {
      long long u, v, p;
      cin >> u >> v >> p;
      edge[u].emplace_back(v, p);
      edge[v].emplace_back(u, p);
    }
    if (!check_bi()) {
      cout << "NO" << '\n';
      continue;
    }
    dfsd(1, 1);
    for (long long i = (1); i <= (n - 1); i += (1)) {
      if (dep[tu[i]] < dep[tv[i]]) swap(tu[i], tv[i]);
      res[tu[i]] = tp[i];
    }
    dfst(1, 1);
    cout << "YES" << '\n';
    for (long long i = (1); i <= (n - 1); i += (1)) {
      cout << tu[i] << " " << tv[i] << " " << res[tu[i]] << '\n';
    }
  }
  return 0;
}
