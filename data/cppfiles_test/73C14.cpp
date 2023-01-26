#include <bits/stdc++.h>
constexpr int Maxn = 7.5e5 + 7;
constexpr int Mod = 1e9 + 7;
int u[Maxn], v[Maxn];
int fa[Maxn], ch[Maxn][2], cnt[Maxn], sum[Maxn], val[Maxn];
int tag[Maxn], rev[Maxn], ty[Maxn], Min[Maxn];
void update(int x, int v) {
  if (x == 0) return;
  sum[x] += cnt[x] * v;
  if (ty[x] == 1) val[x] += v;
  tag[x] += v;
}
void reverse(int x) {
  std::swap(ch[x][0], ch[x][1]);
  rev[x] ^= 1;
}
void pushdown(int x) {
  if (tag[x] != 0) {
    update(ch[x][0], tag[x]);
    update(ch[x][1], tag[x]);
    tag[x] = 0;
  }
  if (rev[x]) {
    reverse(ch[x][0]);
    reverse(ch[x][1]);
    rev[x] = 0;
  }
}
void pushup(int x) {
  if (x == 0) return;
  cnt[x] = cnt[ch[x][0]] + ty[x] + cnt[ch[x][1]];
  sum[x] = sum[ch[x][0]] + val[x] + sum[ch[x][1]];
  Min[x] = std::min(x, std::min(Min[ch[x][0]], Min[ch[x][1]]));
}
int side(int x) { return ch[fa[x]][0] == x ? 0 : ch[fa[x]][1] == x ? 1 : -1; }
void rotate(int x) {
  int y = fa[x], z = fa[y], p = side(x), q = side(y), s = ch[x][p ^ 1];
  if (q != -1) ch[z][q] = x;
  ch[x][p ^ 1] = y, ch[y][p] = s;
  if (s != 0) fa[s] = y;
  fa[y] = x, fa[x] = z;
  pushup(y), pushup(x);
}
void release(int x) {
  if (side(x) != -1) release(fa[x]);
  pushdown(x);
}
void splay(int x, int y = 0) {
  release(x);
  for (; side(x) != -1 && fa[x] != y; rotate(x))
    if (side(fa[x]) != -1 && fa[fa[x]] != y)
      rotate(side(x) == side(fa[x]) ? fa[x] : x);
}
void fix(int x, int y) {
  splay(x);
  ch[x][1] = y;
  pushup(x);
}
void access(int x) {
  fix(x, 0);
  for (; fa[x]; rotate(x)) fix(fa[x], x);
}
void makeroot(int x) {
  access(x);
  reverse(x);
}
void makepath(int x, int y) {
  makeroot(x);
  access(y);
  splay(x, y);
}
bool link(int x, int y, int z) {
  makepath(x, y);
  if (!fa[x]) {
    fa[x] = z;
    fa[z] = y;
    return true;
  }
  if (sum[y] > 0) return false;
  int k = Min[y];
  splay(k);
  fa[ch[k][0]] = 0, ch[k][0] = 0;
  fa[ch[k][1]] = 0, ch[k][1] = 0;
  makepath(x, y);
  fa[x] = z, fa[z] = y;
  makepath(u[k], v[k]);
  update(v[k], 1);
  return true;
}
void cut(int x, int y, int z) {
  makepath(x, y);
  if (sum[y] > 0)
    update(y, -1);
  else {
    fa[ch[x][1]] = 0, ch[x][1] = 0;
    pushup(x);
    fa[x] = 0, ch[y][0] = 0;
    pushup(y);
  }
}
int n, m;
int main() {
  Min[0] = 2e9;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u[i], &v[i]);
    u[i] += m, v[i] += m;
    ty[i] = 1;
  }
  int p = 1;
  long long res = 0;
  for (int i = 1; i <= m; ++i) {
    while (p <= m && link(u[p], v[p], p)) ++p;
    res += p - i;
    cut(u[i], v[i], p);
  }
  printf("%lld\n", res);
}
