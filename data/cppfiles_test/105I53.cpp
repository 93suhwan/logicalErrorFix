#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Res {
  int u, v, l, r, m, id;
  bool operator<(const Res &t) const {
    if (u + v - m == u + v - m) {
      if (l == t.l) {
        return r < t.r;
      }
      return l < t.l;
    }
    return u + v - m < u + v - m;
  }
} a[N];
int u[N], v[N], n;
pair<int, int> calc(int u, int v, int m) {
  if (v >= m) {
    return {max(0, u - m), u};
  }
  return {max(0, u - m), u - (m - v)};
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1, u, v, m; i <= n; i++) {
      scanf("%d %d %d", &u, &v, &m);
      pair<int, int> cur = calc(u, v, m);
      a[i] = {u, v, cur.first, cur.second, m, i};
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int p = i, r = a[i].r;
      while (p < n &&
             a[p + 1].u + a[p + 1].v - a[p + 1].m == a[i].u + a[i].v - a[i].m &&
             a[p + 1].l <= r) {
        p++;
        r = min(a[p].r, r);
      }
      ans++;
      for (int j = i; j <= p; j++) {
        u[a[j].id] = a[j].u - r;
        v[a[j].id] = a[j].m - u[a[j].id];
      }
      i = p;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", u[i], v[i]);
    }
  }
  return 0;
}
