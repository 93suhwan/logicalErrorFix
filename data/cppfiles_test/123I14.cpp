#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    w |= ch == '-';
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return w ? -x : x;
}
int n;
vector<int> G[200005];
int dep[200005], dfn[200005], siz[200005], tot, vis[200005];
int t[200005 * 4], pos[200005 * 4], tag[200005 * 4], fat[200005], rk[200005];
void dfs(int x, int fa) {
  fat[x] = fa;
  dep[x] = dep[fa] + 1;
  dfn[x] = ++tot;
  rk[tot] = x;
  siz[x] = 1;
  for (auto V : G[x]) {
    if (V == fa) continue;
    dfs(V, x), siz[x] += siz[V];
  }
}
inline void pushup(int x) {
  t[x] = max(t[((x) << 1)], t[((x) << 1 | 1)]);
  if (t[((x) << 1)] > t[((x) << 1 | 1)])
    pos[x] = pos[((x) << 1)];
  else
    pos[x] = pos[((x) << 1 | 1)];
}
inline void pushdown(int x) {
  if (!tag[x]) return;
  tag[((x) << 1)] += tag[x];
  t[((x) << 1)] += tag[x];
  tag[((x) << 1 | 1)] += tag[x];
  t[((x) << 1 | 1)] += tag[x];
  tag[x] = 0;
}
void build(int x, int l, int r) {
  if (l == r) {
    pos[x] = l;
    t[x] = dep[rk[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(((x) << 1), l, mid);
  build(((x) << 1 | 1), mid + 1, r);
  pushup(x);
}
void add(int x, int l, int r, int a, int b, int d) {
  if (a <= l && r <= b) {
    t[x] += d;
    tag[x] += d;
    return;
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  if (a <= mid) add(((x) << 1), l, mid, a, b, d);
  if (b > mid) add(((x) << 1 | 1), mid + 1, r, a, b, d);
  pushup(x);
}
void work(int x) {
  if (vis[x] || !x) return;
  add(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, -1);
  work(fat[x]);
}
int main() {
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1, 0);
  build(1, 1, n);
  long long ans = -n * n;
  int num = 0;
  for (int i = 1; i <= k; i++) {
    int now = rk[pos[1]];
    num += t[1];
    long long tmp = min(n / 2, n - num);
    work(now);
    ans = max(ans, (long long)(n - tmp - i) * (i - tmp));
  }
  printf("%lld", ans);
  return 0;
}
