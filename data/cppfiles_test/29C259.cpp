#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long n = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = n * 10 + ch - '0';
    ch = getchar();
  }
  return n * f;
}
long long a[100005];
signed main() {
  long long t, n, s0, s1;
  t = read();
  for (long long greg = 1; greg <= t; greg++) {
    n = read();
    s0 = 0;
    s1 = 0;
    for (long long i = 1; i <= n; i++) {
      a[i] = read();
      if (a[i] == 0)
        s0++;
      else if (a[i] == 1)
        s1++;
    }
    printf("%lld\n", (1LL << s0) * s1);
  }
  return 0;
}
