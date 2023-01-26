#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int Mod = 1e9 + 7;
const long long OO = 1e18;
const int N = 2e5 + 5;
void file() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
}
int ans, n, m, child[N], h[N], ok, cnt, num_odd, num_even, dd[N], sub[N];
vector<int> ad[N];
void dfs(int u, int par, int len) {
  child[u] = 1;
  int num = 0, bud = 1;
  for (int v : ad[u]) {
    if (v == par) continue;
    h[v] = h[u] + 1;
    dfs(v, u, len + 1);
    child[u] += child[v];
    if (child[v] == 1)
      num++;
    else
      bud = 0;
  }
  if (bud && num) {
    ans += num, cnt++;
    dd[u] = 1;
    sub[par]++;
  }
}
void DFS(int u, int par, int st = 0) {
  if (dd[u]) return;
  int leaf = 1;
  for (int v : ad[u]) {
    if (v == par || dd[v]) continue;
    leaf = 0;
    int bro =
        par == 1 ? ad[par].size() - sub[par] : ad[par].size() - sub[par] - 1;
    if (st == 0 && bro == 1 && par != 0)
      DFS(v, u, par);
    else {
      int cha = ad[u].size() - sub[u] - 1;
      if (u == 1) cha++;
      if (cha == 1)
        DFS(v, u, u);
      else
        DFS(v, u, st);
    }
  }
  if (leaf) {
    if (st == 0)
      num_odd++;
    else {
      int len = h[u] - h[st] + 1;
      if (len % 2)
        num_odd++;
      else
        num_even++;
    }
  }
}
void in() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    ad[i].clear(), sub[i] = child[i] = dd[i] = h[i] = 0;
  ans = ok = cnt = num_even = num_odd = 0;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  dfs(1, 0, 0);
  DFS(1, 0);
  ans += num_odd + (num_even || ok);
  int x = min(num_odd, ok + cnt);
  ans -= x;
  cnt -= x;
  if (cnt) ans -= cnt + (num_odd > 0) - 1;
  ans -= num_even;
  cout << ans << '\n';
}
int main() {
  file();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    in();
  }
}
