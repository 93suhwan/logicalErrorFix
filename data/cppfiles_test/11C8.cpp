#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int N = 4e5 + 10, M = 2e5;
int n;
int a[N], cntt = 0;
int f[N], maxx = 0;
struct ppap {
  int x, v;
} b[N];
inline bool cmp(ppap a, ppap b) { return a.v == b.v ? a.x > b.x : a.v < b.v; }
inline void update(int x, int v) {
  for (; x <= M + n; x += x & -x) f[x] = max(f[x], v);
}
inline int smax(int x) {
  int ans = -1;
  for (; x; x -= x & -x) {
    ans = max(ans, f[x]);
  }
  return ans;
}
int main() {
  n = read();
  memset(f, -1, sizeof f);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    b[i] = (ppap){i, a[i]};
    maxx = max(maxx, a[i]);
  }
  sort(b + 1, b + n + 1, cmp);
  update(0 + M, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = b[i].x, y = b[i].v;
    int p = x - y;
    int v = smax(p + M) + 1;
    if (v == 0 && p < 0) v = -1;
    ans = max(ans, v);
    update(p + M, v);
  }
  writeln(ans);
  return 0;
}
