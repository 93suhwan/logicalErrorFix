#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100005];
int de[100005];
int pr[100005][20];
int sa[100005], so[100005];
int cl[100005];
long long b[100005];
int id = 0;
vector<int> g[100005];
void update(int u, int delta) {
  while (u <= n) b[u] += delta, u += u & (-u);
}
long long get(int u) {
  long long res = 0;
  while (u > 0) {
    res += b[u];
    u -= u & (-u);
  }
  return res;
}
void DFS(int u) {
  cl[u] = 1;
  sa[u] = ++id;
  for (auto &v : g[u])
    if (!cl[v]) pr[v][0] = u, de[v] = de[u] + 1, DFS(v);
  so[u] = id;
}
int LCA(int u, int v) {
  while (de[u] > de[v]) {
    int h = log2(de[u] - de[v]);
    u = pr[u][h];
  }
  while (de[v] > de[u]) {
    int h = log2(de[v] - de[u]);
    v = pr[v][h];
  }
  if (u == v) return u;
  int h = log2(de[u]);
  while (h >= 0) {
    if (pr[u][h] != pr[v][h]) u = pr[u][h], v = pr[v][h];
    h--;
  }
  u = pr[u][0];
  return u;
}
int main() {
  ios ::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  de[1] = 1;
  DFS(1);
  int k = log2(n);
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= n; ++j) pr[j][i] = pr[pr[j][i - 1]][i - 1];
  for (int i = 1; i <= n; ++i) update(sa[i], a[i]), update(so[i] + 1, -a[i]);
  for (int i = 1; i <= q; ++i) {
    int tp, u, v;
    cin >> tp >> u >> v;
    if (tp == 1) {
      update(sa[u], -a[u]), update(so[u] + 1, a[u]);
      a[u] = abs(v);
      update(sa[u], a[u]), update(so[u] + 1, -a[u]);
    } else {
      int z = LCA(u, v);
      long long ans = get(sa[u]) + get(sa[v]);
      ans -= 2 * get(sa[z]);
      ans *= 2;
      ans += 2 * a[z];
      ans -= a[u] + a[v];
      cout << ans << "\n";
    }
  }
}
