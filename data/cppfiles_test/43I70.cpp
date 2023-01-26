#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  bool f = true;
  long long x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = false;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  if (f) return x;
  return ~(--x);
}
inline void write(const long long &x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void print(const long long &x) {
  x < 0 ? putchar('-'), write(~(x - 1)) : write(x);
  putchar('\n');
}
inline long long max(const long long &a, const long long &b) {
  return a > b ? a : b;
}
inline long long min(const long long &a, const long long &b) {
  return a < b ? a : b;
}
const int MAXN = 3e5 + 7;
int fa[MAXN], mark[MAXN], cir[MAXN], cost;
int find(int k) { return k == fa[k] ? k : fa[k] = find(fa[k]); }
bool merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return 1;
  fa[v] = u;
  return 0;
}
struct Stack {
  int a[MAXN], Top;
  int size() { return Top; }
  void pop() { Top--; }
  bool empty() { return !Top; }
  void clear() { Top = 0; }
  void push(int x) { a[++Top] = x; }
  int &top() { return a[Top]; }
} sta, vis;
vector<int> g[MAXN], W[MAXN];
bool dfs(int u, int want) {
  if (mark[u]) return 0;
  mark[u] = 1, vis.push(u), sta.push(u);
  if (u == want) return 1;
  for (register int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (cir[u] && cir[v]) continue;
    cost ^= W[u][i];
    if (dfs(v, want)) return 1;
    cost ^= W[u][i];
  }
  sta.pop();
  return 0;
}
int n, m;
int main() {
  n = read(), m = read();
  for (register int i = 1; i <= n; ++i) fa[i] = i;
  for (register int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    if (u == v) {
      puts("NO");
      continue;
    }
    cost = w;
    if (merge(u, v)) {
      if (cir[u] || cir[v]) {
        puts("NO");
        continue;
      }
      sta.clear(), vis.clear();
      if (dfs(u, v)) {
        if (cost & 1) {
          puts("YES");
          while (!sta.empty()) {
            cir[sta.top()] = 1, sta.pop();
          }
        } else
          puts("NO");
      } else
        puts("NO");
      while (!vis.empty()) {
        mark[vis.top()] = 0, vis.pop();
      }
    } else {
      g[u].push_back(v), g[v].push_back(u);
      W[u].push_back(w), W[v].push_back(w);
      puts("YES");
    }
  }
  return 0;
}
