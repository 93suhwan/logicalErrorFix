#include <bits/stdc++.h>
using namespace std;
string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const int INF = 1e9 + 7, N = 1e5 + 7, K = 320;
int p[N], jump[N], ip[N];
bool vis[N];
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    ip[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    jump[i] = i;
    for (int j = 0; j < K; j++) jump[i] = p[jump[i]];
  }
  auto fix = [&](vector<int>& v) {
    assert(v.size());
    jump[v[0]] = v[0];
    for (int j = 0; j < K; j++) jump[v[0]] = p[jump[v[0]]];
    for (int i = 1; i < int(v.size()); i++) jump[v[i]] = p[jump[v[i - 1]]];
  };
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--, y--;
      vector<int> fix1, fix2;
      {
        int u = x;
        fix1.push_back(u);
        while (ip[u] != x && ip[u] != y && int(fix1.size()) < K) {
          u = ip[u];
          fix1.push_back(u);
        }
        reverse((fix1).begin(), (fix1).end());
      }
      {
        int u = y;
        fix2.push_back(u);
        while (ip[u] != x && ip[u] != y && int(fix2.size()) < K) {
          u = ip[u];
          fix2.push_back(u);
        }
        reverse((fix2).begin(), (fix2).end());
      }
      swap(p[x], p[y]);
      swap(ip[p[x]], ip[p[y]]);
      fix(fix1), fix(fix2);
    } else {
      x--;
      while (y >= K) {
        x = jump[x];
        y -= K;
      }
      while (y) {
        x = p[x];
        y--;
      }
      cout << x + 1 << '\n';
    }
  }
}
