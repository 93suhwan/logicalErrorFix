#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 200005;
struct Edge {
  int to, nxt, c, t;
} edge[N << 1];
int head[N], tot;
void add(int u, int v, int c, int t) {
  edge[++tot] = {v, head[u], c, t};
  head[u] = tot;
}
int val[N], n, q;
int ans1 = 0, ans2 = 0;
void dfs(int u, int fa, int c) {
  ckmax(ans1, val[u]);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    if (edge[i].c < c) continue;
    ckmax(ans2, edge[i].t);
    dfs(v, u, c);
  }
}
int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) val[i] = read();
  for (int i = 1; i <= n - 1; i++) {
    int u = read(), v = read(), c = read(), t = read();
    add(u, v, c, t), add(v, u, c, t);
  }
  while (q--) {
    int c = read(), u = read();
    ans1 = ans2 = 0;
    dfs(u, 0, c);
    printf("%d %d\n", ans1, ans2);
  }
  return 0;
}
