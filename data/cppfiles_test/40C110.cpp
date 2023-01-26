#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int sz = 1e6;
int n, m;
vector<int> adj[sz], tadj[sz];
vector<pair<int, int> > qu;
int cnts[sz], f[sz];
bitset<sz> vis;
vector<int> p;
void dfs1(int src, int prv) {
  f[src] = prv;
  vis[src] = 1;
  for (int x : tadj[src]) {
    if (x == prv || vis[x]) continue;
    adj[src].push_back(x);
    adj[x].push_back(src);
    dfs1(x, src);
  }
}
bool dfs2(int src, int goal, int prv) {
  if (src == goal) {
    p.push_back(src + 1);
    return 1;
  }
  for (int x : adj[src]) {
    if (x != prv) {
      if (dfs2(x, goal, src)) {
        p.push_back(src + 1);
        return 1;
      }
    }
  }
  return 0;
}
void tree_solve() {
  for (pair<int, int> ii : qu) {
    int x = ii.first, y = ii.second;
    dfs2(y, x, -1);
    cout << p.size() << '\n';
    for (int z : p) cout << z << ' ';
    cout << '\n';
    p.clear();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    tadj[--x].push_back(--y);
    tadj[y].push_back(x);
  }
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    cnts[--x]++;
    cnts[--y]++;
    qu.push_back({x, y});
  }
  int ocnt = 0;
  for (int i = 0; i < n; i++) {
    if (cnts[i] & 1) ocnt++;
  }
  if (ocnt) {
    cout << "NO\n" << ocnt / 2 << '\n';
    return 0;
  }
  cout << "YES\n";
  dfs1(0, -1);
  tree_solve();
  return 0;
}
