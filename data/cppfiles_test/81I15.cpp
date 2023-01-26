#include <bits/stdc++.h>
template <typename _Tp>
void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
const int N = 1000005;
struct node {
  int s, a;
  inline bool operator<(const node &o) const { return a < o.a; }
} a[N];
int nd[N], n, d;
std::vector<int> e[N];
struct edge {
  int v, nxt;
} c[N << 2];
int front[N], ec, dfn[N], low[N], st[N], top, bel[N], siz[N], id, col;
inline void addedge(int u, int v) {
  c[++ec] = (edge){v, front[u]}, front[u] = ec;
}
void tarjan(int x) {
  dfn[x] = low[x] = ++id, st[++top] = x;
  for (int i = front[x]; i; i = c[i].nxt) {
    int v = c[i].v;
    if (!dfn[v])
      tarjan(v), low[x] = std::min(low[x], low[v]);
    else if (!bel[v])
      low[x] = std::min(low[x], dfn[v]);
  }
  if (dfn[x] == low[x]) {
    bel[x] = ++col, siz[col] = 1 <= x && x <= n;
    while (st[top] != x)
      bel[st[top]] = col, siz[col] += 1 <= st[top] && st[top] <= n, --top;
    --top;
  }
}
int dp[N];
int dfs(int x) {
  if (dp[x] != -1) return dp[x];
  dp[x] = siz[x];
  for (auto v : e[x]) dp[x] = std::max(dp[x], dfs(v) + siz[x]);
  return dp[x];
}
int main() {
  read(n, d);
  for (int i = 1; i <= n; ++i) {
    read(a[i].s, a[i].a);
    if (a[i].s < d) --i, --n;
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i)
    nd[i] = i + n, addedge(nd[i - 1], nd[i]), addedge(i, nd[i]);
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = n, mid;
    while (l < r)
      mid = (l + r + 1) >> 1, a[mid].a <= a[i].s ? l = mid : r = mid - 1;
    addedge(nd[l], i);
  }
  for (int i = 0; i <= n + n; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 0; i <= n + n; ++i) {
    for (int _ = front[i]; _; _ = c[_].nxt) {
      int v = c[_].v;
      if (bel[i] != bel[v]) e[bel[i]].emplace_back(bel[v]);
    }
  }
  memset(dp, -1, sizeof(dp));
  int ans = 0;
  for (int i = 1; i <= col; ++i) ans = std::max(ans, dfs(i));
  printf("%d\n", ans);
  return 0;
}
