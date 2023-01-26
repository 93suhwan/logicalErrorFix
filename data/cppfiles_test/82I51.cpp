#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, f = 1;
  char _ch = getchar();
  while (!('0' <= _ch && _ch <= '9')) (_ch == '-') && (f = -1), _ch = getchar();
  while (('0' <= _ch && _ch <= '9')) s = s * 10 + _ch - 48, _ch = getchar();
  return s * f;
}
const long long N = 3e5 + 10, inf = 1e17;
long long n, q, k, a[N];
long long st[N][20], ts[N][20];
inline void make_table() {
  for (register long long i = 1; i <= n; i++) st[i][0] = a[i], ts[i][0] = i;
  for (long long l = 1; (1 << l) <= n; l++)
    for (long long i = 1; i + (1 << l) - 1 <= n; i++) {
      if (st[i][l - 1] < st[i + (1 << l - 1)][l - 1])
        ts[i][l] = ts[i][l - 1];
      else
        ts[i][l] = ts[i + (1 << l - 1)][l - 1];
      st[i][l] = min(st[i][l - 1], st[i + (1 << l - 1)][l - 1]);
    }
}
inline long long st_Qry(long long l, long long r) {
  if (l > r) return 0;
  if (r > n) r = n;
  long long t = log2(r - l + 1);
  return min(st[l][t], st[r - (1 << t) + 1][t]);
}
inline long long ts_Qry(long long l, long long r) {
  if (l > r) return 0;
  if (r > n) r = n;
  long long t = log2(r - l + 1);
  return (st[l][t] < st[r - (1 << t) + 1][t]) ? ts[l][t]
                                              : ts[r - (1 << t) + 1][t];
}
long long c[N], nxt[N], suf[N];
inline void ycl() {
  for (long long i = n; n - i + 1 <= k; i--) {
    for (long long j = i; j >= 1; j -= k) {
      c[j] = st_Qry(j, j + k - 1);
      if (j == i)
        nxt[j] = n + 1;
      else
        nxt[j] = (c[j] > c[j + k]) ? j + k : nxt[j + k];
    }
  }
  for (long long i = n; i >= 1; i--) {
    if (n - i + 1 <= k)
      suf[i] = c[i];
    else
      suf[i] = suf[nxt[i]] + (nxt[i] - i + k - 1) / k * c[i];
  }
}
inline long long Qry(long long l, long long r) {
  if (r - l + 1 <= k) return a[l];
  long long t = st_Qry(l, r), rr = l + (r - l + 1 + k - 1) / k * k;
  long long p = ts_Qry(l, r), rp = (p - 1) / k * k + 1;
  return suf[l] + a[l] - c[l] - suf[rp] + t * (r - rp + k) / k;
}
signed main() {
  n = read(), q = read(), k = read();
  for (register long long i = 1; i <= n; i++) a[i] = read();
  make_table();
  ycl();
  while (q--) {
    long long l = read(), r = read();
    cout << Qry(l, r) << '\n';
  }
  return 0;
}
