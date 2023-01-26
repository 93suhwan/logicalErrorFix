#include <bits/stdc++.h>
using namespace std;
void FAST_IO(string filein = "", string fileout = "", string fileerr = "") {
  if (fopen(filein.c_str(), "r")) {
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
}
void Hollwo_Pelw();
signed main() {
  FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
  int testcases = 1;
  for (int test = 1; test <= testcases; test++) {
    Hollwo_Pelw();
  }
  return 0;
}
const int M = 1e6 + 5, N = 15e4 + 5;
int par[M], a[N], n, q;
vector<int> pd[M];
struct __init__ {
  __init__() {
    for (int i = 1; i < M; i++) par[i] = i;
    for (int i = 2; i < M; i++)
      if (pd[i].empty())
        for (int j = i; j < M; j += i) pd[j].push_back(i);
  }
} __init__;
int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return 0;
  return par[v] = u, 1;
}
void Hollwo_Pelw() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int x = pd[a[i]].back();
    for (auto v : pd[a[i]]) merge(x, v);
  }
  set<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    vector<int> pds = pd[a[i] + 1];
    pds.insert(pds.end(), pd[a[i]].begin(), pd[a[i]].end());
    for (auto &u : pds) {
      u = find(u);
      for (auto &v : pds) {
        v = find(v);
        if (u > v) swap(u, v);
        if (u != v) st.insert({u, v});
      }
    }
  }
  for (int _ = 0, u, v; _ < q; _++) {
    cin >> u >> v;
    u = find(pd[a[u]].back());
    v = find(pd[a[v]].back());
    if (u > v) swap(u, v);
    if (u == v)
      cout << "0\n";
    else if (st.count({u, v}))
      cout << "1\n";
    else
      cout << "2\n";
  }
}
