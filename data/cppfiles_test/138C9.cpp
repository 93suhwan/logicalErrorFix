#include <bits/stdc++.h>
using namespace std;
int n, m, q;
pair<int, int> a[400005];
struct edge {
  int u, v, w;
} b[400005];
struct query {
  int k, ith;
} que[400005];
long long res, f[400005], ans[400005];
int root[400005], t[400005];
int get(int u) {
  if (root[u] == 0) return u;
  return root[u] = get(root[u]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = 1;
    res += a[i].first;
  }
  for (int i = n + 1; i <= n + m; i++) cin >> a[i].first;
  n += m;
  for (int i = 1; i <= q; i++) {
    cin >> que[i].k;
    que[i].ith = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] + a[i].first;
    t[i] = a[i].second;
  }
  for (int i = 1; i <= n - 1; i++)
    b[i] = {i, i + 1, a[i + 1].first - a[i].first};
  sort(b + 1, b + n, [](edge x, edge y) { return x.w < y.w; });
  int vt = 1;
  sort(que + 1, que + q + 1, [](query x, query y) { return x.k < y.k; });
  for (int i = 1; i <= q; i++) {
    while (vt < n && b[vt].w <= que[i].k) {
      int u = get(b[vt].u);
      int v = get(b[vt].v);
      res -= f[u] - f[u - t[u]];
      res -= f[v] - f[v - t[v]];
      root[u] = v;
      t[v] += t[u];
      res += f[v] - f[v - t[v]];
      vt++;
    }
    ans[que[i].ith] = res;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
