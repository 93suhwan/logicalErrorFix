#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int read() {
  char ch = getchar();
  int x = 0, pd = 0;
  while (ch < '0' || ch > '9') pd |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return pd ? -x : x;
}
namespace modular {
int Add(int x, int y) { return x + y < 998244353 ? x + y : x + y - 998244353; }
int Dec(int x, int y) { return Add(x, 998244353 - y); }
int Mul(int x, int y) { return 1ll * x * y % 998244353; }
int Pow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = Mul(x, x))
    if (y & 1) res = Mul(res, x);
  return res;
}
}  // namespace modular
using namespace modular;
int tot, ch[maxn][26], pos[maxn], fa[maxn];
char str[maxn];
void ins(char *s, int x) {
  int len = strlen(s + 1), r = 0;
  for (int i = 1; i <= len; i++) {
    int d = s[i] - 'a';
    if (!ch[r][d]) ch[r][d] = ++tot, fa[tot] = r, str[tot] = s[i];
    r = ch[r][d];
  }
  pos[x] = r;
}
int n;
char t[maxn];
struct P {
  int x, y;
} p[maxn];
int sz[maxn], son[maxn], d[maxn];
int f[maxn], sum[maxn];
void dfs1(int u) {
  if (u) {
    if (str[u] != str[fa[u]])
      f[u] = Add(sum[fa[u]], 1);
    else
      f[u] = f[fa[u]];
  }
  sum[u] = Add(sum[fa[u]], f[u]);
  sz[u] = 1, d[u] = d[fa[u]] + 1;
  for (int i = 0; i < 26; i++) {
    int v = ch[u][i];
    if (!v) continue;
    dfs1(v), sz[u] += sz[v];
    if (!son[u] || sz[v] > sz[son[u]]) son[u] = v;
  }
}
int id[maxn], cnt, top[maxn];
void dfs2(int u, int t) {
  id[u] = ++cnt, top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int i = 0; i < 26; i++) {
    int v = ch[u][i];
    if (v && v != son[u]) dfs2(v, v);
  }
}
int getlca(int x, int y) {
  while (x[top] != y[top])
    if (d[x[top]] < d[y[top]])
      y = y[top][fa];
    else
      x = x[top][fa];
  return d[x] < d[y] ? x : y;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) scanf("%s", t + 1), ins(t, i);
  for (int i = 0; i < n; i++) p[i] = (P){pos[i + 1], i + 1};
  dfs1(0), dfs2(0, 0);
  sort(p + 1, p + n + 1, [](P A, P B) { return A.x[id] < B.x[id]; });
  long long ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    int Sum = 0, lst = -1, S2 = 0;
    for (int j = 0; j < n; j++)
      if (i >> j & 1) {
        Sum += p[j].y;
        S2 = Add(S2, sum[p[j].x]);
        if (~lst) S2 = Dec(S2, sum[getlca(lst, p[j].x)]);
        lst = p[j].x;
      }
    Sum *= __builtin_popcount(i);
    ans ^= 1ll * Sum * (S2 + 1);
  }
  printf("%lld\n", ans);
  return 0;
}
