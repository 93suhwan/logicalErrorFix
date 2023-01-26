#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, q, tot, v1[N], v2[N], sa[N], rk[N], hgt[N], f[N][19], c[N], lg[N],
    ans[N], tr[N];
int fa[N], son[N], dfn[N], top[N], idx, idf[N], siz[N], dep[N], seq[N], id[N];
char str[N], s[N], vl[N];
vector<pair<int, int>> g[N], up, dn;
struct Q {
  int l, r, id;
};
vector<Q> qr[N];
void modify(int x, int k) {
  for (; x <= m; x += x & -x) tr[x] += k;
}
int query(int x) {
  int ret = 0;
  for (; x; x -= x & -x) ret += tr[x];
  return ret;
}
void build() {
  for (int i = 1; i <= tot; i++) v1[i] = s[i] - 'a' + 1, ++c[v1[i]];
  for (int i = 2; i <= 27; i++) c[i] += c[i - 1];
  for (int i = 1; i <= tot; i++) sa[c[v1[i]]--] = i;
  for (int k = 1; k <= tot; k <<= 1) {
    int cnt = 0;
    memset(c, 0, sizeof(c));
    for (int i = tot - k + 1; i <= tot; i++) v2[++cnt] = i;
    for (int i = 1; i <= tot; i++)
      if (sa[i] > k) v2[++cnt] = sa[i] - k;
    for (int i = 1; i <= tot; i++) c[v1[i]]++;
    for (int i = 1; i <= tot; i++) c[i] += c[i - 1];
    for (int i = tot; i >= 1; i--) {
      sa[c[v1[v2[i]]]--] = v2[i];
      v2[i] = 0;
    }
    swap(v1, v2);
    cnt = 1;
    v1[sa[1]] = 1;
    for (int i = 2; i <= tot; i++) {
      if (v2[sa[i]] == v2[sa[i - 1]] && v2[sa[i] + k] == v2[sa[i - 1] + k])
        v1[sa[i]] = cnt;
      else
        v1[sa[i]] = ++cnt;
    }
  }
  for (int i = 1; i <= tot; i++) rk[sa[i]] = i;
  for (int i = 1, j = 0; i <= tot; i++) {
    if (j) --j;
    while (s[i + j] == s[sa[rk[i] - 1] + j]) j++;
    hgt[rk[i]] = j;
  }
  for (int i = 1; i <= tot; i++) f[i][0] = hgt[i];
  for (int j = 1; j <= 18; j++)
    for (int i = 1; i + (1 << j) - 1 <= tot; i++)
      f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  for (int i = 2; i <= tot; i++) lg[i] = lg[i >> 1] + 1;
}
int lcp(int x, int y) {
  int l = rk[x], r = rk[y];
  if (l == r) return tot - x + 1;
  if (l > r) swap(l, r);
  ++l;
  int k = lg[r - l + 1];
  return min(f[l][k], f[r - (1 << k) + 1][k]);
}
void dfs1(int u) {
  siz[u] = 1;
  for (auto [v, w] : g[u]) {
    if (v == fa[u]) continue;
    fa[v] = u;
    dep[v] = dep[u] + 1;
    vl[v] = w;
    dfs1(v);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int tf) {
  dfn[u] = ++idx;
  seq[idx] = u;
  s[++tot] = vl[u];
  top[u] = tf;
  if (son[u]) dfs2(son[u], tf);
  for (auto [v, w] : g[u]) {
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
int getl() {
  auto check = [&](int x) {
    for (auto [l, r] : up) {
      int lp = lcp(x, l);
      if (lp < r - l + 1) return s[x + lp] < s[l + lp];
      x += r - l + 1;
    }
    return false;
  };
  int l = 0, r = tot;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(sa[mid]))
      l = mid;
    else
      r = mid - 1;
  }
  return l + 1;
}
int getr() {
  auto check = [&](int x) {
    for (auto [l, r] : up) {
      int lp = lcp(x, l);
      if (lp < r - l + 1) return s[x + lp] > s[l + lp];
      x += r - l + 1;
    }
    return false;
  };
  int l = 1, r = tot + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(sa[mid]))
      r = mid;
    else
      l = mid + 1;
  }
  return l - 1;
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    char w;
    scanf("%d %d %c", &u, &v, &w);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vl[1] = 'a';
  dfs1(1);
  dfs2(1, 0);
  for (int i = n; i >= 1; i--) {
    idf[seq[i]] = ++tot;
    s[tot] = vl[seq[i]];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%s", str + 1);
    s[++tot] = 'z' + 1;
    int l = strlen(str + 1);
    for (int j = 1; j <= l; j++) s[++tot] = str[j], id[tot] = i;
  }
  build();
  for (int i = 1; i <= q; i++) {
    dn.clear();
    up.clear();
    int u, v, l, r;
    scanf("%d%d%d%d", &u, &v, &l, &r);
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) {
        dn.push_back({dfn[top[v]], dfn[v]});
        v = fa[top[v]];
      } else {
        up.push_back({idf[u], idf[top[u]]});
        u = fa[top[u]];
      }
    }
    if (dep[u] > dep[v])
      up.push_back({idf[u], idf[v] - 1});
    else if (dep[u] < dep[v])
      dn.push_back({dfn[u] + 1, dfn[v]});
    reverse(dn.begin(), dn.end());
    for (auto p : dn) up.push_back(p);
    int L = getl(), R = getr();
    if (L <= R) {
      qr[L - 1].push_back((Q){l, r, -i});
      qr[R].push_back((Q){l, r, i});
    }
  }
  for (int i = 1; i <= tot; i++) {
    if (id[sa[i]]) modify(id[sa[i]], 1);
    for (auto [l, r, id] : qr[i]) {
      int res = query(r) - query(l - 1);
      if (id < 0)
        ans[-id] -= res;
      else
        ans[id] += res;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
