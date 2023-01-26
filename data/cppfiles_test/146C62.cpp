#include <bits/stdc++.h>
using namespace std;
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
template <typename _T>
void write(_T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
const int N = 100005, SQ = sqrt(N);
int p[N], pinv[N], pa[N], nx[N];
int main() {
  int n, q;
  rd(n), rd(q);
  for (register int i(1); i <= n; ++i) rd(p[i]), pinv[p[i]] = i;
  for (register int i(1); i <= n; ++i) {
    int a = i;
    for (register int j(1); j <= SQ; ++j) a = p[a];
    nx[i] = a;
  }
  while (q--) {
    int t, x, y, i, k;
    rd(t);
    if (t == 1) {
      rd(x), rd(y);
      swap(p[x], p[y]);
      pinv[p[x]] = x;
      pinv[p[y]] = y;
      int a = x;
      for (register int j(1); j <= SQ; ++j) a = p[a];
      nx[x] = a;
      for (register int i(1); i <= SQ; ++i) {
        x = pinv[x];
        a = pinv[a];
        nx[x] = a;
      }
      a = y;
      for (register int i(1); i <= SQ; ++i) a = p[a];
      nx[y] = a;
      for (register int i(1); i <= SQ; ++i) {
        y = pinv[y];
        a = pinv[a];
        nx[y] = a;
      }
    } else {
      rd(i), rd(k);
      while (k >= SQ) i = nx[i], k -= SQ;
      while (k--) i = p[i];
      printf("%d\n", i);
    }
  }
  return 0;
}
