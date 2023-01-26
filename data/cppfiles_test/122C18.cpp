#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 2e5 + 10;
int n, m, parity[maxN];
vector<pair<int, int>> adj[maxN];
bool flag[maxN], ok;
void dfs(int u) {
  flag[u] = 1;
  for (auto &e : adj[u]) {
    int v, w;
    tie(v, w) = e;
    if (!flag[v]) {
      parity[v] = parity[u] ^ w;
      dfs(v);
    } else if ((parity[u] ^ parity[v]) != w) {
      ok = 0;
      return;
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= (int)(n); ++i) {
    adj[i].clear();
  }
  map<pair<int, int>, int> mp;
  vector<pair<int, int>> edges;
  for (int i = 1; i <= (int)(n - 1); ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (w >= 0) {
      mp[{u, v}] = mp[{v, u}] = w;
      int p = __builtin_popcount(w) & 1;
      adj[u].emplace_back(v, p);
      adj[v].emplace_back(u, p);
    }
    edges.emplace_back(u, v);
  }
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  fill(flag + 1, flag + n + 1, 0);
  for (int i = 1; i <= (int)(n); ++i) {
    if (!flag[i]) {
      parity[i] = 0;
      ok = 1;
      dfs(i);
      if (!ok) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  for (auto &edge : edges) {
    int u, v;
    tie(u, v) = edge;
    if (mp.count({u, v})) {
      cout << u << " " << v << " " << mp[{u, v}] << "\n";
    } else {
      cout << u << " " << v << " " << (parity[u] ^ parity[v]) << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
