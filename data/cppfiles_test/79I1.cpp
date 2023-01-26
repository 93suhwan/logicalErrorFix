#include <bits/stdc++.h>
int read(int x = 0, int f = 0, char ch = getchar()) {
  while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
  while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
  return f ? -x : x;
}
const int N = 3e5 + 5;
int n, ans;
int a[N], b[N], f[N], g[N];
std::queue<int> Q;
void print(int x) {
  if (g[x] == -1)
    return printf("%d\n", ans), void();
  else
    ans++, print(g[x]);
  printf("%d ", x);
}
void bfs() {
  Q.push(n), f[n] = 0, g[n] = -1;
  for (int u; !Q.empty();) {
    u = Q.front(), Q.pop();
    for (int i = a[u]; i >= 1; i--) {
      int v1 = std::max(u - i, 0);
      int v2 = std::min(v1 + b[v1], n);
      if (v1 == 0)
        return g[v1] = u, print(v1), void();
      else if (f[u] + 1 < f[v2])
        f[v2] = f[u] + 1, g[v2] = u, Q.push(v2);
    }
  }
  printf("-1");
}
void solve() {
  n = read();
  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  bfs(), puts("");
}
int main() { return solve(), 0; }
