#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int T, n, m, a[N], b[N], l, r, ins[N], las[N];
vector<int> to[N];
struct node {
  int u;
  long long k;
  bool f;
};
node q[N];
inline bool check(long long now) {
  vector<int> s;
  for (int i = 1; i <= n; ++i) ins[i] = las[i] = 0;
  s.push_back(1);
  ins[1] = 1;
  while (s.size() != n) {
    l = 1;
    r = 0;
    for (int i : s) q[++r] = (node){i, now, 0};
    int x = -1, y = -1;
    while (l <= r) {
      node p = q[l++];
      int u = p.u;
      for (int v : to[u]) {
        if (v == las[u]) continue;
        if (p.k <= a[v]) continue;
        if (las[v] || (ins[v] && p.f)) {
          x = u;
          y = v;
          break;
        }
        if (ins[v]) continue;
        las[v] = u;
        q[++r] = (node){v, p.k + b[v], 1};
      }
      if (x != -1) break;
    }
    if (x == -1) return false;
    while (x) {
      if (ins[x]) {
        int r = las[x];
        las[x] = 0;
        x = r;
        continue;
      }
      ins[x] = 1;
      s.push_back(x);
      now += b[x];
      int r = las[x];
      las[x] = 0;
      x = r;
    }
    while (y) {
      if (ins[y]) {
        int r = las[y];
        las[y] = 0;
        y = r;
        continue;
      }
      ins[y] = 1;
      s.push_back(y);
      now += b[y];
      int r = las[y];
      las[y] = 0;
      y = r;
    }
  }
  return true;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 2; i <= n; ++i) scanf("%d", &b[i]);
    for (int i = 1, u, v; i <= m; ++i) {
      scanf("%d%d", &u, &v);
      to[u].push_back(v), to[v].push_back(u);
    }
    int l = 0, r = 1e9 + 1, ans = 1e9 + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        r = mid - 1, ans = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) to[i].clear();
  }
  return 0;
}
