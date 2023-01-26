#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int n, m;
int cnt[MAXN], U[MAXN], V[MAXN];
int ans[MAXN], anstot;
long long Read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
template <typename T>
void Put1(T x) {
  if (x > 9) Put1(x / 10);
  putchar(x % 10 ^ 48);
}
template <typename T>
void Put(T x, char c = -1) {
  if (x < 0) putchar('-'), x = -x;
  Put1(x);
  if (c >= 0) putchar(c);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T Abs(T x) {
  return x < 0 ? -x : x;
}
int head[MAXN], tot;
struct edge {
  int v, nxt;
} e[MAXN << 1];
void Add_Edge(int x, int y) {
  e[++tot] = edge{y, head[x]};
  head[x] = tot;
}
void Add_Double_Edge(int x, int y) {
  Add_Edge(x, y);
  Add_Edge(y, x);
}
int f[MAXN], d[MAXN];
void dfs(int x, int fa) {
  f[x] = fa;
  d[x] = d[fa] + 1;
  for (int i = head[x]; i; i = e[i].nxt)
    if (!d[e[i].v]) dfs(e[i].v, x);
}
void solve(int u, int v) {
  deque<int> q1, q2;
  anstot = 0;
  while (d[u] > d[v]) q1.push_back(u), u = f[u];
  while (d[v] > d[u]) q2.push_back(v), v = f[v];
  while (u ^ v) q1.push_back(u), u = f[u], q2.push_back(v), v = f[v];
  q1.push_back(u);
  while (!q1.empty()) ans[++anstot] = q1.front(), q1.pop_front();
  while (!q2.empty()) ans[++anstot] = q2.back(), q2.pop_back();
}
int main() {
  n = Read();
  m = Read();
  for (int i = 1, u, v; i <= m; ++i) {
    u = Read(), v = Read();
    Add_Double_Edge(u, v);
  }
  dfs(1, 0);
  int Q = Read();
  for (int i = 1; i <= Q; ++i) {
    ++cnt[U[i] = Read()];
    ++cnt[V[i] = Read()];
  }
  int s = 0;
  for (int i = 1; i <= n; ++i)
    if (cnt[i] & 1) ++s;
  if (s) {
    printf("NO\n");
    Put(s >> 1, '\n');
    return 0;
  }
  printf("YES\n");
  for (int i = 1; i <= Q; ++i) {
    solve(U[i], V[i]);
    Put(anstot, '\n');
    for (int j = 1; j <= anstot; ++j) Put(ans[j], j == anstot ? '\n' : ' ');
  }
  return 0;
}
