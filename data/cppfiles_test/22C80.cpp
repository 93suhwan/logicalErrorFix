#include <bits/stdc++.h>
using namespace std;
const int L = 1 << 19;
char ibuf[L], *ie = ibuf + L, *ip = ie - 1;
inline char nc(void) {
  if (++ip == ie)
    if (fread(ip = ibuf, 1, L, stdin))
      ;
  return *ip;
}
inline int read(void) {
  char opt;
  int flag = 1, res = 0;
  while ((opt = nc()) < '0')
    if (opt == '-') flag = -1;
  while (opt >= '0') {
    res = (res << 3) + (res << 1) + opt - '0';
    opt = nc();
  }
  return res * flag;
}
int n, m, lim, rev[400005], s[505][505], d[400005], X[400005], Y[400005], ans;
inline void A(int l, int r, int v) {
  r = min(r, m);
  d[l] += v, d[r + 1] -= v;
}
inline void A(int k, int l, int r, int v) {
  int i;
  for (i = l; i <= r; ++i) s[k][i] += v;
}
inline void A(int pos, int i) {
  int x = X[pos], y = Y[pos], z, l, r;
  rev[pos] = i;
  if (x + y > lim) {
    for (z = i; z <= m; z += x + y) A(z + x, z + x + y - 1, 1);
    return;
  }
  l = (x + i) % (x + y), r = (i - 1) % (x + y);
  if (l <= r)
    A(x + y, l, r, 1);
  else
    A(x + y, 0, r, 1), A(x + y, l, x + y - 1, 1);
}
inline void D(int pos, int i) {
  int x = X[pos], y = Y[pos], z, j = rev[pos], l, r;
  if (x + y > lim) {
    for (z = j; z <= m; z += x + y)
      if (z + x + y - 1 >= i) A(max(i, z + x), z + x + y - 1, -1);
    return;
  }
  i = j, l = (x + i) % (x + y), r = (i - 1) % (x + y);
  if (l <= r)
    A(x + y, l, r, -1);
  else
    A(x + y, 0, r, -1), A(x + y, l, x + y - 1, -1);
  rev[pos] = 0;
}
signed main(void) {
  int i, j, opt, x;
  n = read(), m = read(), lim = 400;
  for (i = 1; i <= n; ++i) X[i] = min(read(), m), Y[i] = min(read(), m);
  for (i = 1; i <= m; ++i) {
    opt = read(), x = read();
    if (opt == 1)
      A(x, i);
    else
      D(x, i);
    d[i] += d[i - 1];
    for (ans = d[i], j = 1; j <= lim; ++j) ans += s[j][i % j];
    printf("%d\n", ans);
  }
  return 0;
}
