#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
void chkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
void chkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
namespace fastio {
char rbuf[1 << 23], *p1 = rbuf, *p2 = rbuf, wbuf[1 << 23], *p3 = wbuf;
inline char getc() {
  return p1 == p2 &&
                 (p2 = (p1 = rbuf) + fread(rbuf, 1, 1 << 23, stdin), p1 == p2)
             ? -1
             : *p1++;
}
inline void putc(char x) { (*p3++ = x); }
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T neg = 0;
  while (!isdigit(c)) neg |= (c == '-'), c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (neg) x = -x;
}
template <typename T>
void recursive_print(T x) {
  if (!x) return;
  recursive_print(x / 10);
  putc(x % 10 + '0');
}
template <typename T>
void print(T x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  recursive_print(x);
}
template <typename T>
void print(T x, char c) {
  print(x);
  putc(c);
}
void print_final() { fwrite(wbuf, 1, p3 - wbuf, stdout); }
}  // namespace fastio
template <typename Tv, int limN, int limM>
struct link_list {
  int hd[limN + 5], nxt[limM + 5], item_n = 0;
  Tv val[limM + 5];
  void clear() {
    memset(hd, 0, sizeof(hd));
    item_n = 0;
  }
  void ins(int x, Tv y) {
    val[++item_n] = y;
    nxt[item_n] = hd[x];
    hd[x] = item_n;
  }
};
const int MAXN = 3e5;
int n, m, qu, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {
  to[++ec] = v;
  nxt[ec] = hd[u];
  hd[u] = ec;
}
int fa[MAXN + 5], vis[MAXN + 5], dep[MAXN + 5];
int a[MAXN + 5], b[MAXN + 5], c[MAXN + 5];
void dfs(int x, int f) {
  fa[x] = f;
  vis[x] = 1;
  for (int e = hd[x]; e; e = nxt[e]) {
    int y = to[e];
    if (vis[y]) continue;
    dep[y] = dep[x] + 1;
    dfs(y, x);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i <= m; i++)
    scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
  dfs(1, 0);
  scanf("%d", &qu);
  for (int i = 1; i <= qu; i++)
    scanf("%d%d", &a[i], &b[i]), c[a[i]] ^= 1, c[b[i]] ^= 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += c[i];
  if (cnt)
    printf("NO\n%d\n", cnt >> 1);
  else {
    printf("YES\n");
    for (int i = 1; i <= qu; i++) {
      vector<int> pu, pv;
      int u = a[i], v = b[i];
      while (dep[u] > dep[v]) pu.push_back(u), u = fa[u];
      while (dep[v] > dep[u]) pv.push_back(v), v = fa[v];
      while (u ^ v) pu.push_back(u), pv.push_back(v), u = fa[u], v = fa[v];
      pu.push_back(u);
      printf("%d\n", pu.size() + pv.size());
      for (int j = 0; j < pu.size(); j++) printf("%d ", pu[j]);
      for (int j = (int)(pv.size()) - 1; ~j; j--) printf("%d ", pv[j]);
      printf("\n");
    }
  }
  return 0;
}
