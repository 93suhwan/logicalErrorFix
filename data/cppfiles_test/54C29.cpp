#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = (int)1e6 + 1000;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int s = 0, w = 1;
  char ch = nc();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = nc();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = nc();
  }
  return s * w;
}
int n, cnt, m, a, b;
bool ok = false;
int vis[4 * MAXN], head[MAXN];
struct Edge {
  int next, to;
} edge[4 * MAXN];
void add(int u, int v) {
  edge[++cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt;
}
void dfs(int k, int col) {
  vis[k] = col;
  if (k <= n) {
    if (col == 1)
      a++;
    else
      b++;
  }
  for (int i = head[k]; i; i = edge[i].next) {
    if (vis[edge[i].to] == vis[k]) {
      ok = false;
      return;
    }
    if (vis[edge[i].to] != -1) continue;
    vis[edge[i].to] = 1 - vis[k];
    dfs(edge[i].to, 1 - vis[k]);
  }
}
char s[20];
inline void work(int CASE = 1, bool FINAL_CASE = false) {
  scanf("%d%d", &n, &m);
  cnt = 0;
  ok = true;
  for (int i = 0; i <= 2 * n + m; i++)
    vis[i] = -1, head[i] = 0, edge[i].next = 0;
  int u, v, fake = n;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    scanf("%s", s + 1);
    if (s[1] == 'i') {
      add(u, v);
      add(v, u);
    } else {
      add(u, ++fake);
      add(fake, u);
      add(fake, v);
      add(v, fake);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == -1) {
      a = 0, b = 0;
      dfs(i, 0);
      ans += max(a, b);
    }
  }
  if (!ok) ans = -1;
  printf("%d\n", ans);
  return;
}
signed main() {
  signed T = 1;
  scanf("%d", &T);
  for (signed CASE = 1; CASE <= T; CASE++) {
    work(CASE, CASE == T);
  }
  return 0;
}
