#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 1010, mod = 31607;
long long a[N], x[N], y[N], mark[N], q[N];
long long n, fl, k;
int main() {
  for (long long T = read(); T--;) {
    n = read();
    k = read();
    memset(mark, 0, sizeof mark);
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    for (long long i = (long long)(1); i <= (long long)(k); ++i)
      x[i] = read(), y[i] = read(), mark[x[i]] = mark[y[i]] = 1;
    long long pos = 1, sm = 0;
    *q = 0;
    for (long long i = (long long)(1); i <= (long long)(2 * n); ++i)
      if (!mark[i]) q[++*q] = i;
    for (long long i = (long long)(1); i <= (long long)(*q / 2); ++i) {
      x[++k] = q[i];
      y[k] = q[i + *q / 2];
    }
    for (long long i = (long long)(1); i <= (long long)(n); ++i)
      if (x[i] > y[i]) swap(x[i], y[i]);
    long long ans = 0;
    for (long long i = (long long)(1); i <= (long long)(n); ++i)
      for (long long j = (long long)(1); j <= (long long)(n); ++j)
        ans += x[i] < x[j] && x[j] < y[i] && y[i] < y[j];
    cout << ans << endl;
  }
}
