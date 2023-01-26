#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char c = getchar();
  while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
}
template <class T>
bool umax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
template <class T>
bool umin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
const int N = 1e6 + 5, inf = 1e9;
int n, m, q, vis[N], flag = 0, minr[N], db;
struct edge {
  int u, v, eg;
} e[N];
int ch[N][2], fa[N], mx[N], val[N], tag[N], tim[N], mi[N], add_tag[N];
void Pushup(int x) {
  if (x > n) mx[x] = max(mx[x], val[x]);
  mi[x] = x;
  if (ch[x][0] && tim[mi[ch[x][0]]] < tim[mi[x]]) mi[x] = mi[ch[x][0]];
  if (ch[x][1] && tim[mi[ch[x][1]]] < tim[mi[x]]) mi[x] = mi[ch[x][1]];
  if (ch[x][0]) umax(mx[x], mx[ch[x][0]]);
  if (ch[x][1]) umax(mx[x], mx[ch[x][1]]);
}
void Pushdown(int x) {
  if (tag[x]) {
    swap(ch[ch[x][0]][0], ch[ch[x][0]][1]);
    swap(ch[ch[x][1]][0], ch[ch[x][1]][1]);
    tag[ch[x][0]] ^= 1;
    tag[ch[x][1]] ^= 1;
    tag[x] = 0;
  }
  add_tag[ch[x][0]] += add_tag[x];
  add_tag[ch[x][1]] += add_tag[x];
  val[ch[x][0]] += add_tag[x];
  val[ch[x][1]] += add_tag[x];
  mx[ch[x][0]] += add_tag[x];
  mx[ch[x][1]] += add_tag[x];
  add_tag[x] = 0;
}
void Rotate(int x) {
  int y = fa[x], z = fa[y], k = (ch[fa[x]][1] == x);
  if (!(ch[fa[y]][0] != y && ch[fa[y]][1] != y)) ch[z][(ch[fa[y]][1] == y)] = x;
  fa[ch[x][!k]] = y;
  ch[y][k] = ch[x][!k];
  ch[x][!k] = y;
  fa[x] = z;
  fa[y] = x;
  Pushup(y);
  Pushup(x);
}
void Update(int x) {
  if (!(ch[fa[x]][0] != x && ch[fa[x]][1] != x)) Update(fa[x]);
  Pushdown(x);
}
void Splay(int x) {
  Update(x);
  for (int pa = 0; pa = fa[x], !(ch[fa[x]][0] != x && ch[fa[x]][1] != x);
       Rotate(x))
    if (!(ch[fa[pa]][0] != pa && ch[fa[pa]][1] != pa))
      Rotate((ch[fa[pa]][1] == pa) == (ch[fa[x]][1] == x) ? pa : x);
}
int Access(int x) {
  int R;
  for (R = 0; x; R = x, x = fa[x]) {
    Splay(x);
    ch[x][1] = R;
    Pushup(x);
  }
  return R;
}
void Makeroot(int x) {
  int tp = Access(x);
  tag[tp] ^= 1;
  swap(ch[tp][0], ch[tp][1]);
  Splay(x);
}
int Find(int x) {
  Access(x);
  Splay(x);
  while (ch[x][0]) Pushdown(x), x = ch[x][0];
  Splay(x);
  return x;
}
bool Link(int x, int y) {
  Makeroot(x);
  if (Find(y) == x) return 0;
  fa[x] = y;
  return 1;
}
bool Cut(int x, int y) {
  Makeroot(x);
  if (Find(y) == x && !ch[y][0] && fa[y] == x) {
    ch[x][1] = fa[y] = 0;
    Pushup(x);
    return 1;
  }
  return 0;
}
int curt = 0, ok;
void try_add(int i) {
  int u = e[i].u, v = e[i].v, md = e[i].eg;
  Makeroot(u);
  tim[md] = ++curt;
  if (Find(v) == u) {
    Makeroot(u);
    Access(v);
    Splay(v);
    if (mx[v] == 1) {
      ok = 0;
      return;
    }
    val[v]++;
    add_tag[v]++;
    mx[v]++;
    Splay(u);
    int j = mi[v] - n;
    Cut(e[j].u, e[j].eg);
    Cut(e[j].v, e[j].eg);
    val[e[j].eg] = 1;
  }
  Link(u, md);
  Link(v, md);
}
void delet(int i) {
  int u = e[i].u, v = e[i].v, md = e[i].eg;
  Makeroot(u);
  Access(v);
  Splay(v);
  val[v]--;
  add_tag[v]--;
  mx[v]--;
  Splay(u);
  Cut(u, md);
  Cut(v, md);
}
int main() {
  read(n);
  read(m);
  memset(tim, 0x3f, sizeof(tim));
  memset(val, 0, sizeof(val));
  memset(mx, 0, sizeof(mx));
  int cnt = n;
  for (int i = 1; i <= m; ++i) {
    read(e[i].u);
    read(e[i].v);
    e[i].eg = ++cnt;
  }
  long long ans = 0;
  int cannot = 0;
  for (int i = 1, j = 0; i <= m; ++i) {
    if (i == 2) db = 1;
    ok = 1;
    while (ok && j < m) {
      try_add(j + 1);
      if (ok) j++;
    }
    ans += j - i + 1;
    delet(i);
  }
  cout << ans << endl;
  return 0;
}
