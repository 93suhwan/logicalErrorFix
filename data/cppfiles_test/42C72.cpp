#include <bits/stdc++.h>
using std::pair;
using std::vector;
const int N = 400005, MOD = 1000000007;
inline int mval(int first) { return first >= MOD ? first - MOD : first; }
inline void inc(int &first, int a) { first = mval(first + a); }
int n, t, in[N], f[N], g[N], a[N], b[N], id[N], sum[N];
int mx[N];
vector<int> qid[N];
inline void add(int p, int first) {
  while (p <= 2 * n) inc(sum[p], first), p += p & (-p);
}
inline int ask(int p) {
  int ret = 0;
  while (p) inc(ret, sum[p]), p -= p & (-p);
  return ret;
}
inline void add1(int p, int first) {
  while (p <= 2 * n) mx[p] = std::max(mx[p], first), p += p & (-p);
}
inline int ask1(int p) {
  int ret = 0;
  while (p) ret = std::max(ret, mx[p]), p -= p & (-p);
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", a + i, b + i), id[b[i]] = i;
  scanf("%d", &t);
  for (int i = 1, first; i <= t; ++i) scanf("%d", &first), in[first] = 1;
  for (int i = 1; i <= 2 * n; ++i)
    if (in[id[i]]) {
      int u = id[i];
      int t = id[ask1(2 * n - a[u] + 1)];
      qid[t].push_back(u);
      add1(2 * n - a[u] + 1, b[u]);
    }
  int t = id[ask1(2 * n)];
  a[n + 1] = 1;
  qid[t].push_back(n + 1);
  for (int i = 1; i <= 2 * n; ++i)
    if (id[i]) {
      int u = id[i];
      f[u] = mval(1 + ask(2 * n - a[u] + 1));
      if (in[u]) {
        inc(g[u], 1);
        for (int first : qid[u])
          g[first] = mval(ask(2 * n - a[first] + 1) + g[u]);
      }
      add(2 * n - a[u] + 1, f[u]);
    }
  printf("%d\n", g[n + 1]);
  return 0;
}
