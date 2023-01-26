#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
const long long N(2e5 + 10);
long long n, m;
long long a[N];
long long b[N];
long long c[N];
long long d[N];
inline void work() {
  n = read(), m = read();
  long long sa = 0, sb = 0;
  for (long long i = (1); i <= (n); i++) a[i] = read(), b[i] = read();
  long long ans = 0;
  for (long long i = (1); i <= (n); i++) {
    if (a[i] >= m)
      c[i] = m, d[i] = 0;
    else
      c[i] = a[i], d[i] = m - a[i];
    ans += (a[i] - c[i]) - (b[i] - d[i]);
  }
  if (ans < 0)
    for (long long i = (1); i <= (n); i++) {
      long long t = abs(ans) / 2;
      t = min(t, min(c[i], b[i] - d[i]));
      ans += t * 2, c[i] -= t, d[i] += t;
    }
  cout << (long long)(abs(ans)) << endl;
  for (long long i = (1); i <= (n); i++) cout << c[i] << ' ' << d[i] << endl;
}
signed main() {
  long long tasks = read();
  while (tasks--) work();
  return 0;
}
