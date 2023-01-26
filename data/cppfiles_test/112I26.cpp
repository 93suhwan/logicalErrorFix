#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int nex, to, len;
} edge[200005];
int n, m, q, x, y, z, l, r, ans, mi[200005];
int E, head[200005], dep[200005], w[200005], fa[200005][17], fU[200005][17],
    fD[200005][17];
int S[200005], posl[200005], posr[200005], a[200005], b[200005], c[200005],
    tot[200005], rk[200005 << 1], sa[200005], sum[200005];
int V, rt[200005], ls[200005 * 20], rs[200005 * 20], f[200005 * 20];
char s[200005];
void add(int x, int y, int z) {
  edge[E] = Edge{head[x], y, z};
  head[x] = E++;
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 16; i >= 0; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 16; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
void dfs(int k, int f, int s, int lst) {
  dep[k] = s, w[k] = lst;
  fa[k][0] = f, fU[k][0] = fD[k][0] = lst;
  for (int i = 1; i < 17; i++) {
    fa[k][i] = fa[fa[k][i - 1]][i - 1];
    fU[k][i] =
        (fU[fa[k][i - 1]][i - 1] + (long long)mi[1 << i - 1] * fU[k][i - 1]) %
        998244353;
    fD[k][i] =
        (fD[k][i - 1] + (long long)mi[1 << i - 1] * fD[fa[k][i - 1]][i - 1]) %
        998244353;
  }
  for (int i = head[k]; i != -1; i = edge[i].nex)
    if (edge[i].to != f) dfs(edge[i].to, k, s + 1, edge[i].len);
}
int Hash(int x, int y) {
  return (sum[y] - (long long)mi[y - x + 1] * sum[x - 1] % 998244353 +
          998244353) %
         998244353;
}
void build() {
  for (int i = 1; i <= n; i++)
    sum[i] = ((long long)47 * sum[i - 1] + S[i]) % 998244353;
  int m = 27;
  for (int i = 1; i <= n; i++) rk[i] = S[i];
  for (int i = 1;; i <<= 1) {
    memset(tot, 0, sizeof(tot));
    for (int j = 1; j <= n; j++) tot[rk[j + i]]++;
    for (int j = 1; j <= m; j++) tot[j] += tot[j - 1];
    for (int j = n; j; j--) a[tot[rk[j + i]]--] = j;
    memset(tot, 0, sizeof(tot));
    for (int j = 1; j <= n; j++) tot[rk[j]]++;
    for (int j = 1; j <= m; j++) tot[j] += tot[j - 1];
    for (int j = n; j; j--) b[tot[rk[a[j]]]--] = a[j];
    m = 0;
    for (int j = 1; j <= n; j++) {
      if ((j == 1) || (rk[b[j]] != rk[b[j - 1]]) ||
          (rk[b[j] + i] != rk[b[j - 1] + i]))
        m++;
      c[b[j]] = m;
    }
    memcpy(rk, c, sizeof(c));
    if (m == n) break;
  }
  for (int i = 1; i <= n; i++) sa[rk[i]] = i;
}
int cmp(int l, int r) {
  int k = x;
  for (int i = 16; i >= 0; i--)
    if ((dep[fa[k][i]] >= dep[z]) && (l + (1 << i) - 1 <= r)) {
      if (fU[k][i] == Hash(l, l + (1 << i) - 1)) k = fa[k][i], l += (1 << i);
    }
  if (l > r) return (y == z) - 1;
  if (k != z) return ((w[k] < S[l]) << 1) - 1;
  vector<int> v;
  for (int i = y; i != z; i = fa[i][0]) v.push_back(w[i]);
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if ((l > r) || (S[l] < v[i])) return -1;
    if (S[l] > v[i]) return 1;
    l++;
  }
  return l <= r;
}
int New(int k) {
  f[++V] = f[k], ls[V] = ls[k], rs[V] = rs[k];
  return V;
}
void update(int &k, int l, int r, int x) {
  k = New(k), f[k]++;
  if (l == r) return;
  int mid = (l + r >> 1);
  if (x <= mid)
    update(ls[k], l, mid, x);
  else
    update(rs[k], mid + 1, r, x);
}
int query(int k, int l, int r, int x, int y) {
  if ((!k) || (l > y) || (x > r)) return 0;
  if ((x <= l) && (r <= y)) return f[k];
  int mid = (l + r >> 1);
  return query(ls[k], l, mid, x, y) + query(rs[k], mid + 1, r, x, y);
}
int main() {
  mi[0] = 1;
  for (int i = 1; i < 200005; i++)
    mi[i] = (long long)47 * mi[i - 1] % 998244353;
  scanf("%d%d%d", &n, &m, &q);
  memset(head, -1, sizeof(head));
  for (int i = 1; i < n; i++) {
    scanf("%d%d%s", &x, &y, s);
    add(x, y, s[0] - 'a' + 1), add(y, x, s[0] - 'a' + 1);
  }
  dfs(1, 0, 1, 0);
  n = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    posl[i] = n + 1;
    for (int j = 0; s[j]; j++) S[++n] = s[j] - 'a' + 1;
    posr[i] = n;
    if (i < m) S[++n] = 27;
  }
  build();
  for (int i = 1; i <= n; i++) {
    rt[i] = rt[i - 1];
    update(rt[i], 1, n, sa[i]);
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &x, &y, &l, &r), z = lca(x, y);
    int d = dep[x] + dep[y] - (dep[z] << 1), L = posl[l], R = posr[r] - d + 1;
    l = 1, r = n;
    while (l < r) {
      int mid = (l + r >> 1);
      if (cmp(sa[mid], n) >= 0)
        r = mid;
      else
        l = mid + 1;
    }
    r = n, ans = query(rt[l - 1], 1, n, L, R);
    while (l < r) {
      int mid = (l + r + 1 >> 1);
      if ((sa[mid] + d - 1 <= n) && (!cmp(sa[mid], sa[mid] + d - 1)))
        l = mid;
      else
        r = mid - 1;
    }
    ans = query(rt[l], 1, n, L, R) - ans;
    printf("%d\n", ans);
  }
  return 0;
}
