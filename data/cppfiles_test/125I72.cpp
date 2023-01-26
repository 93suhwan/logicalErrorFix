#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 100;
int n, m, a[N], match[N], L[N], R[N], w, vi[N];
vector<tuple<int, int, int> > e, E;
vector<pair<int, int> > to[N];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
struct dsu {
  int fa[N], sz[N], ok[N];
  void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1, ok[i] = -1;
  }
  int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
  bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (sz[a] > sz[b]) swap(a, b);
    fa[a] = b;
    sz[b] += sz[a];
    return 1;
  }
} T;
void dfs(int x, int fa) {
  for (auto [u, id] : to[x])
    if (u != fa) {
      match[u] = id;
      dfs(u, x);
    }
}
namespace maxmatch {
int ver, tr[N], vi[N], lk[N], dfn, id[N];
vector<int> e[N];
mt19937 rnd(time(0));
void add(int x, int y) {
  e[x].push_back(y);
  e[y].push_back(x);
}
bool dfs(int x) {
  shuffle(e[x].begin(), e[x].end(), rnd);
  vi[x] = dfn;
  for (int u : e[x]) {
    int f = lk[u];
    if (vi[f] == dfn) continue;
    lk[x] = u;
    lk[u] = x;
    lk[f] = 0;
    if (!f) return 1;
    if (dfs(f)) return 1;
    lk[u] = f;
    lk[f] = u;
    lk[x] = 0;
  }
  return 0;
}
void solve(vector<tuple<int, int, int> > p) {
  ver = m;
  for (auto [u, v, w] : p)
    if (w != 0) tr[w] = ++ver, id[ver] = w;
  for (auto [u, v, w] : p) {
    if (w > 0)
      add(u, tr[w]), add(tr[w], v);
    else if (match[u] != -1 && match[v] != -1)
      add(u, v);
  }
  vector<int> cur(ver);
  for (int i = 1; i <= ver; i++) cur[i - 1] = i;
  int cnt = 0;
  for (int h = 0; h < 13 || cnt < 600; h++) {
    shuffle(cur.begin(), cur.end(), rnd);
    cnt++;
    for (auto v : cur)
      if (!lk[v]) dfn++, dfs(v), cnt++;
  }
  for (int i = 1; i <= m; i++) {
    if (match[i] != -1 || lk[i] > m) {
      if (match[i] == 0) continue;
      int x = (match[i] != -1) ? match[i] : id[lk[i]];
      if (a[L[x] - 1] == i)
        a[L[x]] = i;
      else
        a[R[x]] = i;
    }
  }
  for (auto [u, v, w] : p)
    if (lk[u] == v && lk[v] == u) {
      a[L[-w]] = a[L[-w] - 1];
      a[R[-w]] = a[R[-w] + 1];
      lk[u] = lk[v] = 0;
    }
}
}  // namespace maxmatch
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  m = *max_element(a + 1, a + 1 + n);
  if (all_of(a + 1, a + 1 + n, [](int x) { return x == 0; })) {
    for (int i = 1; i <= n; i += 2) a[i] = a[i + 1] = (i + 1) / 2;
    if (n & 1) a[n] = 1;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n && (a[i] == 0) == (a[j] == 0)) j++;
    if (a[i] == 0) {
      L[++w] = i;
      R[w] = j - 1;
      ans += (j - i) / 2;
      if ((j - i) & 1) {
        if (i == 1)
          E.emplace_back(a[j], a[j], w);
        else if (j == n + 1)
          E.emplace_back(a[i - 1], a[i - 1], w);
        else
          E.emplace_back(a[i - 1], a[j], w);
      } else if (i != 1 && j != n + 1)
        e.emplace_back(a[i - 1], a[j], -w);
    }
    i = j;
  }
  for (int i = 1; i < n; i++)
    if (a[i] == a[i + 1] && a[i] > 0) E.emplace_back(a[i], a[i], 0);
  T.init(m);
  for (int i = 0; i < (int)E.size(); i++) {
    auto [u, v, w] = E[i];
    if (T.merge(u, v)) {
      to[u].emplace_back(v, w);
      to[v].emplace_back(u, w);
      vi[i] = 1;
    }
  }
  for (int i = 0; i < (int)E.size(); i++)
    if (!vi[i]) {
      auto [u, v, w] = E[i];
      if (T.ok[T.find(u)] == -1) T.ok[T.find(u)] = i;
    }
  for (int i = 0; i < (int)E.size(); i++)
    if (vi[i] && T.ok[T.find(get<0>(E[i]))] == -1) {
      assert(get<2>(E[i]) != 0);
      e.emplace_back(E[i]);
    }
  memset(vi, 0, sizeof(vi));
  memset(match, -1, sizeof(match));
  for (int i = 1; i <= m; i++)
    if (T.find(i) == i && T.ok[i] != -1) {
      auto [u, v, w] = E[T.ok[i]];
      dfs(u, u);
      match[u] = w;
    }
  maxmatch::solve(e);
  memset(vi, 0, sizeof(vi));
  for (int i = 1; i < n; i++)
    if (a[i] == a[i + 1] && a[i] > 0) vi[a[i]] = 1;
  vector<int> it;
  for (int i = 1; i <= n; i++)
    if (!vi[i]) it.push_back(i);
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n && (a[i] == 0) == (a[j] == 0)) j++;
    if (a[i] == 0) {
      for (int k = i; k < j; k += 2) {
        if (!it.empty())
          a[k] = a[k + 1] = it.back(), it.pop_back();
        else
          a[k] = a[k + 1] = 1;
      }
      if ((j - i) & 1) a[j - 1] = 1;
    }
    i = j;
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
}
