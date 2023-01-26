#include <bits/stdc++.h>
using namespace std;
int sa[200010], x[200010 << 1], y[200010], sl[200010], N;
void getsa(int n, int m, char zf[200010]) {
  N = n;
  for (int i = 0; i < n; i++) sl[x[i] = zf[i]] += 1;
  for (int i = 1; i <= m; i++) sl[i] += sl[i - 1];
  for (int i = n - 1; i >= 0; i--) sa[--sl[x[i]]] = i;
  for (int mi = 1; mi <= n; mi *= 2) {
    int s = 0;
    for (int i = n - mi; i < n; i++) y[s++] = i;
    for (int i = 0; i < n; i++) {
      if (sa[i] >= mi) y[s++] = sa[i] - mi;
    }
    for (int i = 1; i <= m; i++) sl[i] = 0;
    for (int i = 0; i < n; i++) sl[x[i]] += 1;
    for (int i = 1; i <= m; i++) sl[i] += sl[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--sl[x[y[i]]]] = y[i];
    m = 1;
    for (int i = 0; i < n; i++) {
      if (i != 0 &&
          (x[sa[i]] != x[sa[i - 1]] || x[sa[i] + mi] != x[sa[i - 1] + mi]))
        m += 1;
      y[sa[i]] = m;
    }
    if (m == n) break;
    for (int i = 0; i < n; i++) x[i] = y[i];
  }
}
unsigned long long ha[200010], mi[200010], hz[200010], H[100010];
char S[200010], ch[100010], fb[100010];
int st[100010], wz[100010], sd[100010], cd[100010];
unsigned long long getha1(int l, int r) {
  if (l == 0) return ha[r];
  return ha[r] - ha[l - 1] * mi[r - l + 1];
}
unsigned long long getha2(int l, int r) {
  return hz[l] - hz[r + 1] * mi[r - l + 1];
}
unsigned long long getha3(int a, int b) {
  return H[a] - H[b] * mi[sd[a] - sd[b]];
}
int lg[100010], bz[17][100010], le[100010], top[100010], son[100010],
    fa[100010];
vector<int> li[100010], up[100010], ve[100010];
vector<char> vw[100010];
void addb(int a, int b, char c) {
  ve[a].push_back(b);
  vw[a].push_back(c);
}
int dfs(int u, int f) {
  sd[u] = sd[f] + 1;
  fa[u] = f;
  int mx = 0;
  son[u] = -1;
  for (int i = 0; i < ve[u].size(); i++) {
    int t = ve[u][i];
    if (t == f) continue;
    H[t] = H[u] * 20060915 + vw[u][i];
    fb[t] = vw[u][i];
    int rt = dfs(t, u);
    if (rt > mx) mx = rt, son[u] = t;
  }
  return le[u] = mx + 1;
}
void dfs2(int u, int f, int tp) {
  top[u] = tp;
  if (son[u] == -1) return;
  dfs2(son[u], u, tp);
  for (int i : ve[u]) {
    if (i != son[u] && i != f) dfs2(i, u, i);
  }
}
void yucl(int n) {
  dfs(1, 0);
  dfs2(1, 0, 1);
  for (int i = 1; i <= n; i++) {
    int x = 0;
    while ((2 << x) <= i) x += 1;
    lg[i] = x;
    bz[0][i] = fa[i];
  }
  for (int i = 1; i <= 16; i++) {
    for (int j = 1; j <= n; j++) bz[i][j] = bz[i - 1][bz[i - 1][j]];
  }
  for (int i = 1; i <= n; i++) {
    if (i == son[fa[i]]) continue;
    for (int s = 0, u = i; s < le[i]; s++, u = son[u]) li[i].push_back(u);
    for (int s = 0, u = i; s < le[i]; s++, u = fa[u]) up[i].push_back(u);
  }
}
int getkth(int x, int k) {
  if (k == 0) return x;
  int g = lg[k];
  x = bz[g][x];
  k ^= (1 << g);
  int s = sd[x] - k - sd[top[x]];
  if (s >= 0) return li[top[x]][s];
  return up[top[x]][-s];
}
int cmp1(int u, int x) {
  for (int i = 16; i >= 0; i--) {
    if (bz[i][u] == 0 || (x + (1 << i)) > N) continue;
    if (getha3(u, bz[i][u]) == getha2(x, x + (1 << i) - 1))
      u = bz[i][u], x += (1 << i);
  }
  return (int)fb[u] - S[x];
}
int cmp2(int c, int u, int x) {
  if (x + (sd[u] - sd[c]) <= N &&
      getha3(u, c) == getha1(x, x + (sd[u] - sd[c]) - 1))
    return 0;
  for (int i = 16; i >= 0; i--) {
    if ((1 << i) > (sd[u] - sd[c]) || (x + (1 << i)) > N) continue;
    int t = getkth(u, (sd[u] - sd[c]) - (1 << i));
    if (getha3(t, c) == getha1(x, x + (1 << i) - 1)) c = t, x += (1 << i);
  }
  u = getkth(u, sd[u] - sd[c] - 1);
  return (int)fb[u] - S[x];
}
int getlca(int x, int y) {
  if (sd[x] < sd[y]) {
    int t = x;
    x = y;
    y = t;
  }
  for (int i = 16; i >= 0; i--) {
    if (sd[bz[i][x]] >= sd[y]) x = bz[i][x];
  }
  int rt;
  if (x == y) return x;
  for (int i = 16; i >= 0; i--) {
    if (bz[i][x] != bz[i][y])
      x = bz[i][x], y = bz[i][y];
    else
      rt = bz[i][x];
  }
  return rt;
}
int compare(int u, int v, int x) {
  int c = getlca(u, v);
  if (x + (sd[u] - sd[c]) <= N &&
      getha3(u, c) == getha2(x, x + (sd[u] - sd[c]) - 1))
    return cmp2(c, v, x + (sd[u] - sd[c]));
  return cmp1(u, x);
}
int efcz1(int u, int v) {
  int l = 0, r = N;
  while (l < r) {
    int m = (l + r) >> 1;
    if (compare(u, v, sa[m]) <= 0)
      r = m;
    else
      l = m + 1;
  }
  return l;
}
int efcz2(int u, int v) {
  int l = -1, r = N - 1;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    if (compare(u, v, sa[m]) >= 0)
      l = m;
    else
      r = m - 1;
  }
  return l;
}
int cl[10000010], cr[10000010], su[10000010], ss = 0;
int build(int l, int r) {
  int rt = ++ss;
  if (l + 1 == r) return rt;
  int m = (l + r) >> 1;
  cl[rt] = build(l, m);
  cr[rt] = build(m, r);
  return rt;
}
int modify(int i, int l, int r, int j) {
  int rt = ++ss;
  cl[rt] = cl[i];
  cr[rt] = cr[i];
  su[rt] = su[i] + 1;
  if (l + 1 == r) return rt;
  int m = (l + r) >> 1;
  if (j < m)
    cl[rt] = modify(cl[i], l, m, j);
  else
    cr[rt] = modify(cr[i], m, r, j);
  return rt;
}
int sum(int i, int l, int r, int L, int R) {
  if (r <= L || R <= l) return 0;
  if (L <= l && r <= R) return su[i];
  int m = (l + r) >> 1;
  return sum(cl[i], l, m, L, R) + sum(cr[i], m, r, L, R);
}
int ro[200010];
int main() {
  int n, m, q, k = 0;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    char c[2];
    scanf("%d%d%s", &a, &b, c);
    addb(a, b, c[0]);
    addb(b, a, c[0]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%s", ch);
    int c = strlen(ch);
    st[i] = k;
    cd[i] = c;
    for (int j = 0; j < c; j++) S[k + j] = ch[j];
    S[k + c] = 1;
    k += c + 1;
  }
  getsa(k, 'z', S);
  mi[0] = 1;
  for (int i = 1; i <= n || i <= k; i++) mi[i] = mi[i - 1] * 20060915;
  for (int i = 0; i < k; i++) {
    if (i > 0) ha[i] = ha[i - 1] * 20060915;
    ha[i] += S[i];
  }
  for (int i = k - 1; i >= 0; i--) hz[i] = hz[i + 1] * 20060915 + S[i];
  yucl(n);
  ro[0] = build(0, k);
  for (int i = 1; i <= k; i++) ro[i] = modify(ro[i - 1], 0, k, sa[i - 1]);
  for (int i = 0; i < q; i++) {
    int u, v, l, r;
    scanf("%d%d%d%d", &u, &v, &l, &r);
    int L = st[l], R = st[r] + cd[r];
    int wl = efcz1(u, v) + 1, wr = efcz2(u, v) + 1;
    int ans = 0;
    if (wl <= wr)
      ans = sum(ro[wr], 0, k, L, R + 1) - sum(ro[wl - 1], 0, k, L, R + 1);
    printf("%d\n", ans);
  }
  return 0;
}
