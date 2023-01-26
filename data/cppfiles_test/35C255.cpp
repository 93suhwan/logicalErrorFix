#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch = getchar();
  long long f = 0;
  x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  if (f) x = -x;
}
long long n, m, pw[35];
signed main() {
  pw[0] = 1;
  for (long long i = 1; i <= 30; ++i) pw[i] = pw[i - 1] * 2;
  long long T;
  read(T);
  while (T--) {
    read(n), read(m);
    if (n > m) {
      puts("0");
      continue;
    }
    if (n == 0) {
      printf("%lld\n", m + 1);
      continue;
    }
    if (m == 0) {
      puts("0");
      continue;
    }
    long long p = n ^ m, mxa = 0, mxb = 0;
    for (long long i = 0; i <= 30; ++i) {
      if (n & pw[i]) mxa = i;
      if (m & pw[i]) mxb = i;
    }
    long long tag = 0;
    for (long long i = max(mxa, mxb); i >= 0; --i)
      if (p & pw[i]) {
        if ((n ^ (p ^ pw[i])) > m) p ^= pw[i], tag = 1;
      }
    if (!tag) {
      for (long long i = 0; i <= 30; ++i) {
        if (p & pw[i])
          p ^= pw[i];
        else if (((p ^ pw[i]) ^ n) > m) {
          p ^= pw[i];
          break;
        }
      }
    }
    printf("%lld\n", p);
  }
}
