#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int f = 1, x = 0;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return f * x;
}
const int N = 5e5 + 5, inf = 2e9;
int n, fd, d, ans = 0;
int m1 = 0, m2 = 0, m3 = 0;
int del[N];
struct node {
  int s, a;
} p[N], b[N], c[N], tb[N];
inline bool cmp1(const node &a, const node &b) { return a.a < b.a; }
inline bool cmp2(const node &a, const node &b) { return a.s < b.s; }
int main() {
  n = read(), fd = read();
  for (int i = 1; i <= n; i++) p[i].s = read(), p[i].a = read();
  for (int i = 1; i <= n; i++) {
    if (p[i].s < fd) continue;
    if (p[i].s < p[i].a)
      b[++m1] = p[i];
    else
      c[++m2] = p[i];
  }
  sort(b + 1, b + m1 + 1, cmp1);
  sort(c + 1, c + m2 + 1, cmp2);
  int j = 1;
  while (j <= m1 && b[j].a <= c[1].s) j++;
  int now = c[1].a;
  c[m2 + 1].s = inf;
  for (int i = 2; i <= m2 + 1; i++) {
    while (j <= m1 && b[j].a <= c[i].s) {
      if (b[j].s < now) del[j] = 1;
      j++;
    }
    now = max(now, c[i].a);
  }
  for (int i = 1; i <= m1; i++)
    if (!del[i]) tb[++m3] = b[i];
  ans = m2;
  int d = fd;
  for (int i = 1; i <= m3; i++) {
    if (tb[i].s >= d) {
      d = max(tb[i].a, d);
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
