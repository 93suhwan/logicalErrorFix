#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c & 15), c = getchar();
  return f ? -x : x;
}
const int MAXN = 2e5;
struct w {
  int to, nx;
} head[MAXN + MAXN + 10];
int a[MAXN + 10];
inline void add(int x, int y, int i) {
  head[i].to = y, head[i].nx = a[x], a[x] = i;
}
int cnt[MAXN + 10], op[MAXN + 10];
void dfs(int x, int fa) {
  cnt[x] = 0, op[x] = -1;
  for (int i = a[x]; i; i = head[i].nx) {
    int v = head[i].to;
    if (v == fa) continue;
    dfs(v, x);
    cnt[x] += cnt[v];
    if (op[v] == -1) op[x] = 1;
  }
  if (x == 1) op[1] = 0;
  cnt[x] += op[x];
}
int sum[MAXN + 10], leaf[MAXN + 10];
void dfs2(int x, int fa) {
  leaf[x] = (!head[a[x]].nx && x != 1);
  sum[x] = sum[fa] + op[x];
  if (op[x] < 0 && leaf[x]) ++sum[x];
  for (int i = a[x]; i; i = head[i].nx) {
    int v = head[i].to;
    if (v == fa) continue;
    dfs2(v, x);
  }
}
int main() {
  int T = read();
  while (T--) {
    int n = read();
    for (int i = 1; i <= n; ++i) a[i] = leaf[i] = 0;
    for (int i = 1; i < n; ++i) {
      int x = read(), y = read();
      add(x, y, i + i - 1);
      add(y, x, i + i);
    }
    dfs(1, 0);
    dfs2(1, 0);
    int res = n, ans = -cnt[1];
    for (int i = 1; i <= n; ++i) {
      if (leaf[i]) res = min(res, sum[i]);
    }
    ans += res;
    printf("%d\n", ans);
  }
  return 0;
}
