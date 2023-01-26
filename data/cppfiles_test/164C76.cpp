#include <bits/stdc++.h>
using namespace std;
const int N = 202020;
int n, k, l[N], r[N];
string c;
vector<int> a;
bool good[N], vis[N];
void dfs1(int u) {
  if (u == 0) return;
  dfs1(l[u]);
  a.push_back(u);
  dfs1(r[u]);
}
void dfs2(int u, int cost = 1) {
  if (!u) return;
  if (cost > k) return;
  dfs2(l[u], cost + 1);
  if (vis[l[u]])
    vis[u] = 1;
  else if (good[u]) {
    vis[u] = 1;
    k -= cost;
  }
  if (vis[u]) dfs2(r[u], 1);
}
int main() {
  cin >> n >> k >> c;
  c = ' ' + c;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  dfs1(1);
  char ch = c[a.back()];
  for (int i = n - 2; i >= 0; i--) {
    int u = a[i], v = a[i + 1];
    if (c[u] != c[v]) ch = c[v];
    if (c[u] < ch) good[u] = true;
  }
  dfs2(1);
  for (auto u : a) {
    cout << c[u];
    if (vis[u]) cout << c[u];
  }
}
