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
const int N = 5e5 + 5;
int n, d, ans = 0;
struct node {
  int s, a;
} p[N];
inline bool cmp(const node &x, const node &y) {
  if (max(x.a, x.s) != max(y.a, y.s)) return max(x.a, x.s) < max(y.a, y.s);
  return min(x.a, x.s) < min(y.a, y.s);
}
int main() {
  n = read(), d = read();
  for (int i = 1; i <= n; i++) p[i].s = read(), p[i].a = read();
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (p[i].s >= d) {
      d = max(p[i].a, d);
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
