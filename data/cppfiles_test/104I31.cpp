#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005], ta[200005], tb[200005];
template <typename _T>
void rd(_T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9')
    x = (x << 3) + (x << 1) + (s ^ 48), s = getchar();
  x *= f;
}
void slv() {
  int n, m;
  rd(n), rd(m);
  int s = 0;
  for (register int i(1); i <= n; ++i) {
    rd(a[i]), rd(b[i]);
    ta[i] = min(m, a[i]), tb[i] = m - ta[i];
    s += a[i] - ta[i];
    s -= b[i] - tb[i];
  }
  for (register int i(1); i <= n; ++i) {
    if (s >= 0) break;
    int t = min((-s + 1) / 2, min(ta[i], b[i] - tb[i]));
    tb[i] += t;
    ta[i] -= t;
    s += (t << 1);
  }
  printf("%d\n", abs(s));
  for (register int i(1); i <= n; ++i) printf("%d %d\n", ta[i], tb[i]);
  return;
}
int main() {
  int _;
  for (rd(_); _; _--) slv();
  return 0;
}
