#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const double pi = acos(-1.0);
inline void read(long long &a) {
  a = 0;
  long long d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
}
long long fpm(long long b, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * b) % M;
    p >>= 1;
    b = (b * b) % M;
  }
  return ans;
}
long long cc(long long n, long long m) {
  long long ans = 1;
  m = min(m, n - m);
  for (long long i = 0; i < m; i++) ans = (ans * (n - i) / (1 + i)) % M;
  return ans;
}
signed main() {
  long long t;
  read(t);
  while (t--) {
    long long n, k;
    read(n);
    read(k);
    if (k == 0) {
      printf("1\n");
      continue;
    }
    if (n % 2 == 0) {
      long long a = fpm(2, n);
      long long b = fpm(2, n - 1) - 1;
      long long ans = fpm(b, k);
      for (long long i = 1; i <= k; i++)
        ans = (ans + fpm(a, k - i) * fpm(b, i - 1)) % M;
      printf("%lld\n", ans);
    } else {
      long long b = 1 + fpm(2, n - 1);
      long long ans = fpm(b, k);
      printf("%lld\n", ans);
    }
  }
  return 0;
}
