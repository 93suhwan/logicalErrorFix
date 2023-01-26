#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10, INF = 1e9;
int n, u, v, k, sz[MAXN], dfn[MAXN], fa[MAXN], top[MAXN], depth[MAXN];
int m, leaf[MAXN], leafd[MAXN];
vector<int> e[MAXN];
void dfs(int u) {
  sz[u] = 1;
  dfn[u] = ++dfn[0];
  depth[u] = depth[fa[u]] + 1;
  top[u] = u;
  for (auto v : e[u]) {
    if (v == fa[u]) continue;
    fa[v] = u;
    dfs(v);
    sz[u] += sz[v];
  }
}
void up(pair<int, int>& a, pair<int, int> b) {
  if (a.first < b.first) a = b;
}
bool cmp(int a, int b) { return dfn[a] < dfn[b]; }
struct seg {
  int tag[MAXN << 2], maxn[MAXN << 2], pos[MAXN << 2];
  void pushup(int x) {
    if (maxn[(x << 1)] > maxn[((x << 1) | 1)])
      maxn[x] = maxn[(x << 1)], pos[x] = pos[(x << 1)];
    else
      maxn[x] = maxn[((x << 1) | 1)], pos[x] = pos[((x << 1) | 1)];
  }
  void pushdown(int x) {
    if (!tag[x]) return;
    maxn[(x << 1)] += tag[x];
    maxn[((x << 1) | 1)] += tag[x];
    tag[(x << 1)] += tag[x];
    tag[((x << 1) | 1)] += tag[x];
    tag[x] = 0;
  }
  void build(int x, int l, int r) {
    if (l == r) {
      pos[x] = l;
      maxn[x] = depth[leaf[l]];
      return;
    }
    int mid = (l + r) >> 1;
    build((x << 1), l, mid);
    build(((x << 1) | 1), mid + 1, r);
    pushup(x);
  }
  void upd(int x, int l, int r, int pos, int val) {
    if (l == r) {
      maxn[x] = val;
      return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    if (pos <= mid)
      upd((x << 1), l, mid, pos, val);
    else
      upd(((x << 1) | 1), mid + 1, r, pos, val);
    pushup(x);
  }
  void upd(int x, int l, int r, int ql, int qr, int val) {
    if (ql <= l && qr >= r) {
      maxn[x] += val;
      tag[x] += val;
      return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    if (ql <= mid) upd((x << 1), l, mid, ql, qr, val);
    if (qr > mid) upd(((x << 1) | 1), mid + 1, r, ql, qr, val);
    pushup(x);
  }
} t;
int ban;
void Remove(int u) {
  int L = dfn[u], R = dfn[u] + sz[u] - 1;
  int l = lower_bound(leafd + 1, leafd + 1 + m, L) - leafd;
  int r = upper_bound(leafd + 1, leafd + 1 + m, R) - leafd - 1;
  if (l <= r) t.upd(1, 1, m, l, r, -1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (1); i <= (n - 1); i++) {
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1);
  for (int i = (1); i <= (n); i++)
    if (sz[i] == 1) {
      leaf[++m] = i;
    }
  sort(leaf + 1, leaf + 1 + m, cmp);
  for (int i = (1); i <= (m); i++) leafd[i] = dfn[leaf[i]];
  if (k >= m) {
    if (k < n / 2) {
      printf("%lld", 1LL * (n - k) * k);
    } else {
      if (m <= n / 2)
        printf("%lld", 1LL * (n - n / 2) * (n / 2));
      else
        printf("%lld", 1LL * (n - m) * m);
    }
    return 0;
  }
  t.build(1, 1, m);
  long long ans = -1e18;
  for (int i = (1); i <= (k); i++) {
    pair<int, int> tmp = make_pair(t.maxn[1], t.pos[1]);
    ban += (tmp.first - 1);
    int u = leaf[tmp.second];
    t.upd(1, 1, n, tmp.second, -INF);
    while (u) {
      Remove(u);
      top[u] = top[fa[u]];
      u = top[u];
    }
    int b = n - i - ban;
    long long cur = (long long)(n - i - b) * (i - b);
    for (int j = (-1); j <= (1); j++)
      if (n / 2 + j <= b && n / 2 + j >= 0)
        cur = min(cur, (long long)(n - i - n / 2 - j) * (i - n / 2 - j));
    ans = max(ans, cur);
  }
  printf("%lld", ans);
  return 0;
}
