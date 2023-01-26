#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int n, m;
int X[N], Y[N];
int fa[N], son[N][2], siz[N], sum[N], tag[N], val[N], simo[N], stk[N];
bool rev[N];
long long ans;
bool isroot(int x) { return son[fa[x]][0] != x && son[fa[x]][1] != x; }
bool locate(int x) { return son[fa[x]][1] == x; }
void update(int x) {
  siz[x] = siz[son[x][0]] + siz[son[x][1]] + (x <= m);
  sum[x] = sum[son[x][0]] + sum[son[x][1]] + val[x];
  simo[x] = x;
  if (son[x][0]) simo[x] = min(simo[x], simo[son[x][0]]);
  if (son[x][1]) simo[x] = min(simo[x], simo[son[x][1]]);
}
void pusht(int x, int k) {
  if (x <= m) val[x] += k;
  tag[x] += k;
  sum[x] += siz[x] * k;
}
void pushr(int x) {
  swap(son[x][0], son[x][1]);
  rev[x] ^= 1;
}
void pushdown(int x) {
  if (tag[x]) {
    if (son[x][0]) pusht(son[x][0], tag[x]);
    if (son[x][1]) pusht(son[x][1], tag[x]);
    tag[x] = 0;
  }
  if (rev[x]) {
    if (son[x][0]) pushr(son[x][0]);
    if (son[x][1]) pushr(son[x][1]);
    rev[x] = false;
  }
}
void rotate(int x) {
  int y = fa[x], z = fa[y], side = locate(x);
  if (!isroot(y)) son[z][son[z][1] == y] = x;
  son[y][side] = son[x][side ^ 1], fa[x] = z;
  if (son[y][side]) fa[son[y][side]] = y;
  son[x][side ^ 1] = y, fa[y] = x;
  update(y), update(x);
}
void splay(int x) {
  int y = x, top = 0;
  while (!isroot(y)) stk[++top] = y, y = fa[y];
  stk[++top] = y;
  while (top) pushdown(stk[top--]);
  while (!isroot(x)) {
    y = fa[x];
    if (!isroot(y)) rotate(locate(x) == locate(y) ? y : x);
    rotate(x);
  }
  update(x);
}
void access(int x) {
  for (int y = 0; x; y = x, x = fa[x]) splay(x), son[x][1] = y, update(x);
}
void makeroot(int x) {
  access(x), splay(x);
  pushr(x);
}
void split(int x, int y) {
  makeroot(x), access(y);
  splay(y);
}
void link(int x, int y, int i) {
  split(x, y);
  if (!fa[x]) {
    fa[i] = y, fa[x] = i;
    return;
  }
  int z = simo[y];
  splay(z);
  fa[son[z][0]] = fa[son[z][1]] = 0;
  son[z][0] = son[z][1] = 0;
  split(x, y);
  fa[x] = i, fa[i] = y;
  split(X[z], Y[z]);
  pusht(Y[z], 1);
}
void cut(int x, int y) {
  split(x, y);
  if (sum[y]) {
    pusht(y, -1);
    return;
  }
  if (son[y][0] == x) {
    fa[son[x][1]] = 0, son[x][1] = 0;
    fa[x] = 0, son[y][0] = 0;
  } else {
    fa[son[y][0]] = 0, son[y][0] = 0;
    son[fa[x]][0] = 0, fa[x] = 0;
  }
}
int main() {
  read(n), read(m);
  for (int i = 1; i <= m; i++) read(X[i]), read(Y[i]), X[i] += m, Y[i] += m;
  int now = 1;
  for (int i = 1; i <= m; i++) {
    while (now < i) {
      split(X[i], Y[i]);
      if (!fa[X[i]] || !sum[Y[i]]) break;
      cut(X[now], Y[now]);
      now++;
    }
    link(X[i], Y[i], i);
    ans += i - now + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
