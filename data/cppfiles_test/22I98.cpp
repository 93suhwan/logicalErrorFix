#include <bits/stdc++.h>
long long read(long long x = 0, long long f = 0, char ch = getchar()) {
  while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
  while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
  return f ? -x : x;
}
const long long N = 1e6 + 5;
const long long S = 450;
long long n, m;
long long sum, cur;
long long x[N], y[N], d0[N], d1[S + 5][S + 5], beg[N];
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; i++) x[i] = read(), y[i] = read();
  for (long long i = 1; i <= m; i++) {
    long long opt = read() == 1 ? 1 : -1, k = read();
    long long x = ::x[k], y = ::y[k];
    if (opt == 1)
      beg[k] = i;
    else {
      if ((i - 1 - beg[k]) % (x + y) < x) cur--;
    }
    sum += opt;
    if (x + y < S) {
      d1[x + y][beg[k] % (x + y)] += opt;
      d1[x + y][(beg[k] + x) % (x + y)] -= opt;
    } else {
      for (long long j = beg[k]; j < m; j += x + y) d0[j] += opt;
      for (long long j = beg[k] + x; j < m; j += x + y) d0[j] -= opt;
    }
    cur += d0[i];
    for (long long j = 2; j < S; j++) cur += d1[j][i % j];
    printf("%lld\n", sum - cur);
  }
  return 0;
}
