#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, ans, fl[maxn], leaf[maxn];
int head[maxn], ecnt;
struct edge {
  int to, next;
} e[maxn << 1];
void adde(int u, int v) {
  e[++ecnt].to = v;
  e[ecnt].next = head[u];
  head[u] = ecnt;
}
int read() {
  int res = 0, f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (!isdigit(ch));
  do {
    res = res * 10 + ch - '0';
    ch = getchar();
  } while (isdigit(ch));
  return res * f;
}
void dfs1(int u, int fa) {
  fl[u] = leaf[u] = 1;
  for (int _ = head[u], v; _ && (v = e[_].to); _ = e[_].next)
    if (v != fa) {
      dfs1(v, u);
      if (!fl[v]) leaf[u] = 0;
      if (!leaf[v]) fl[u] &= fl[v];
    }
  if (leaf[u]) fl[u] = 0;
  ans += leaf[u];
  if (u == 1) return;
  ans -= fl[u];
}
void solve() {
  n = read();
  ans = 0;
  ecnt = 0;
  for (int i = (1); i <= (n); ++i) head[i] = 0;
  for (int i = (2); i <= (n); ++i) {
    int u = read(), v = read();
    adde(u, v);
    adde(v, u);
  }
  dfs1(1, 0);
  printf("%d\n", ans);
}
signed main() {
  int T = read();
  while (T--) solve();
}
