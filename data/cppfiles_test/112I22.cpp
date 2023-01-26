#include <bits/stdc++.h>
using namespace std;
int n, m, q;
struct edge {
  int v, w, nxt;
} e[100010 * 2];
int head[100010], cnte = 0;
void ad(int u, int v, int w) {
  e[++cnte].v = v;
  e[cnte].w = w;
  e[cnte].nxt = head[u];
  head[u] = cnte;
}
char s1[100010];
char s[100010];
int len = 0;
unsigned long long bas = 13131;
unsigned long long ha1[100010], ha2[100010], mi[100010];
unsigned long long gethash1(int l, int r) {
  return ha1[r] - ha1[l - 1] * mi[r - l + 1];
}
unsigned long long gethash2(int l, int r) {
  return ha2[l] - ha2[r + 1] * mi[r + 1 - l];
}
int dep[100010];
int f[100010][20], logn;
int fval[100010], sonval[100010];
unsigned long long val[100010];
int son[100010], maxdep[100010], top[100010];
int hbit[100010];
vector<int> fa1[100010], son1[100010];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    f[v][0] = u;
    val[v] = val[u] * bas + e[i].w;
    fval[v] = e[i].w;
    dfs1(v, u);
    if (!son[u] || maxdep[v] > maxdep[son[u]]) {
      son[u] = v;
      maxdep[u] = maxdep[v] + 1;
    }
  }
}
void init() {
  while ((1 << logn) <= n) logn++;
  for (int j = 1; j <= logn; j++)
    for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
  for (int i = 1; i <= n; i++)
    for (int j = 20; j >= 0; j--)
      if (i >> j & 1) {
        hbit[i] = j;
        break;
      }
}
void getson(int u, int tp, int len) {
  if (!u) return;
  if (!len) return;
  son1[tp].push_back(u);
  getson(son[u], tp, len - 1);
}
void getfa(int u, int tp, int len) {
  if (!u) return;
  if (!len) return;
  fa1[tp].push_back(u);
  getfa(f[u][0], tp, len - 1);
}
void dfs2(int u, int fa) {
  if (son[fa] == u)
    top[u] = top[fa];
  else
    top[u] = u;
  if (top[u] == u) {
    getfa(u, u, maxdep[u] + 1);
    getson(u, u, maxdep[u] + 1);
  }
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    if (v == son[u]) sonval[u] = e[i].w;
    dfs2(v, u);
  }
}
int getlca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int j = logn; j >= 0; j--)
    if (dep[f[u][j]] >= dep[v]) u = f[u][j];
  if (u == v) return u;
  for (int j = logn; j >= 0; j--)
    if (f[u][j] != f[v][j]) {
      u = f[u][j];
      v = f[v][j];
    }
  return f[u][0];
}
unsigned long long get_tre_hash(int u, int fu) {
  if (dep[u] < dep[fu]) return 0;
  return val[u] - val[fu] * mi[dep[u] - dep[fu]];
}
int get_kth(int u, int k) {
  if (k == 0) return u;
  u = f[u][hbit[k]], k -= (1 << hbit[k]);
  k -= dep[u] - dep[top[u]], u = top[u];
  if (k >= 0)
    return fa1[u][k];
  else
    return son1[u][-k];
}
int sa[100010], rk[100010 * 2], rk2[100010 * 2];
int cnt[100010], id[100010];
bool equ(int i, int w) {
  return rk2[sa[i]] == rk2[sa[i - 1]] && rk2[sa[i] + w] == rk2[sa[i - 1] + w];
}
void getsa() {
  int m = 300, p = 0;
  for (int i = 1; i <= len; i++) rk[i] = s[i];
  for (int i = 1; i <= len; i++) cnt[rk[i]]++;
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = len; i >= 1; i--) sa[cnt[rk[i]]--] = i;
  for (int w = 1; w <= len; w <<= 1, m = p) {
    p = 0;
    for (int i = len; i > len - w; i--) id[++p] = i;
    for (int i = 1; i <= len; i++)
      if (sa[i] > w) id[++p] = sa[i] - w;
    for (int i = 1; i <= m; i++) cnt[i] = 0;
    for (int i = 1; i <= len; i++) cnt[rk[id[i]]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = len; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];
    memcpy(rk2, rk, sizeof(rk));
    p = 0;
    for (int i = 1; i <= len; i++)
      if (equ(i, w))
        rk[sa[i]] = p;
      else
        rk[sa[i]] = ++p;
    if (p == len) break;
  }
}
int li[100010], ri[100010];
int root[100010];
int sz = 0;
struct Tre {
  int sum;
  int ls, rs;
} tre[100010 * 17 * 4];
void pushup(int rt) {
  int ls = tre[rt].ls, rs = tre[rt].rs;
  tre[rt].sum = tre[ls].sum + tre[rs].sum;
}
void update(int &rt, int l, int r, int k, int x) {
  rt = ++sz;
  tre[rt] = tre[k];
  if (l == r) {
    tre[rt].sum++;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(tre[rt].ls, l, mid, tre[k].ls, x);
  else
    update(tre[rt].rs, mid + 1, r, tre[k].rs, x);
  pushup(rt);
}
int getsum(int rt1, int rt2, int l, int r, int L, int R) {
  if (!rt2) return 0;
  if (L <= l && r <= R) return tre[rt2].sum - tre[rt1].sum;
  int mid = (l + r) >> 1;
  int ans = 0;
  if (L <= mid) ans += getsum(tre[rt1].ls, tre[rt2].ls, l, mid, L, R);
  if (mid < R) ans += getsum(tre[rt1].rs, tre[rt2].rs, mid + 1, r, L, R);
  return ans;
}
int cmp1(int i, int u, int fa) {
  int l = 1, r = dep[u] - dep[fa];
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (get_tre_hash(u, get_kth(u, mid)) == gethash2(i, i + mid - 1)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  u = get_kth(u, ans);
  return s[i + ans] - fval[u];
}
int cmp2(int i, int u, int fa) {
  int len1 = dep[u] - dep[fa];
  int l = 1, r = dep[u] - dep[fa];
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (get_tre_hash(get_kth(u, len1 - mid), fa) == gethash1(i, i + mid - 1)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (ans == len1) return 0;
  u = get_kth(u, len1 - ans);
  return s[i + ans] - sonval[u];
}
int check(int i, int u, int v) {
  int lca = getlca(u, v);
  int len1 = dep[u] - dep[lca], len2 = dep[v] - dep[lca];
  if (gethash2(i, i + len1 - 1) == get_tre_hash(u, lca))
    return cmp2(i + len1, v, lca);
  else
    return cmp1(i, u, lca);
}
int getans(int u, int v, int L, int R) {
  int l = 1, r = len;
  int lx = 0, rx = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(sa[mid], u, v) < 0) {
      lx = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  lx++;
  l = lx, r = len;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(sa[mid], u, v) > 0) {
      rx = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  rx--;
  return getsum(root[L - 1], root[R], 1, len, lx, rx);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    scanf("%s", s1);
    int c = s1[0];
    ad(u, v, c);
    ad(v, u, c);
  }
  dfs1(1, 0);
  init();
  dfs2(1, 0);
  s[++len] = 'z' + 1;
  for (int i = 1; i <= m; i++) {
    scanf("%s", s1 + 1);
    li[i] = len + 1;
    strcat(s + 1, s1 + 1);
    len += strlen(s1 + 1);
    ri[i] = len;
    s[++len] = '*';
  }
  for (int i = 1; i <= len; i++) ha1[i] = ha1[i - 1] * bas + s[i];
  for (int i = len; i >= 1; i--) ha2[i] = ha2[i + 1] * bas + s[i];
  mi[0] = 1;
  for (int i = 1; i <= len; i++) mi[i] = mi[i - 1] * bas;
  getsa();
  for (int i = 1; i <= m; i++) {
    update(root[i], 1, len, root[i - 1], rk[li[i]]);
    for (int j = li[i] + 1; j <= ri[i]; j++)
      update(root[i], 1, len, root[i], rk[j]);
  }
  for (int i = 1; i <= q; i++) {
    int u, v, l, r;
    scanf("%d%d%d%d", &u, &v, &l, &r);
    printf("%d\n", getans(u, v, l, r));
  }
  return 0;
}
