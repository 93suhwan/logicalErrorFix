#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 6000005;
int n, c, p[N], d[N], x, y, s, sv = INT_MAX;
vector<int> e[N];
map<int, int> mp;
int id(int x) {
  if (mp.find(x) == mp.end()) {
    c++;
    mp[x] = c;
  }
  return mp[x];
}
int fa(int x) {
  int v = 1 << (31 - __builtin_clz(x));
  return v == x ? 0 : v * 2 - x;
}
int ins(int v) {
  if (mp.find(v) != mp.end()) return mp[v];
  int z = id(v);
  while (v) {
    int u = fa(v), f = 0;
    if (mp.find(u) != mp.end()) f = 1;
    int x = id(u), y = id(v);
    e[x].push_back(y);
    e[y].push_back(x);
    v = u;
    if (f) break;
  }
  return z;
}
void dfs(int u, int f) {
  d[u] = d[f] + 1;
  for (auto v : e[u])
    if (v != f) dfs(v, u);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    p[ins(v)] = i;
    if (v < sv) sv = v, s = i;
  }
  dfs(1, 0);
  for (int i = 1; i <= c; i++)
    if (d[i] > d[x]) x = i;
  dfs(x, 0);
  for (int i = 1; i <= c; i++)
    if (d[i] > d[y]) y = i;
  if (!p[x]) p[x] = s;
  if (!p[y]) p[y] = s;
  printf("%d %d %d\n", p[x], p[y], d[y] - 1);
  return 0;
}
