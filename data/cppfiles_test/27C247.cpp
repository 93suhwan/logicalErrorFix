#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10, P = 998244353;
const double Pi = acos(-1);
inline long long read() {
  long long x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
inline long long Add(long long a, long long b) {
  return a + b >= P ? a + b - P : a + b;
}
inline long long Sub(long long a, long long b) {
  return a - b < 0 ? a - b + P : a - b;
}
inline long long Mul(long long a, long long b) {
  long long res = 1ll * a * b;
  return res >= P ? res % P : res;
}
inline long long Pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = Mul(res, a);
    a = Mul(a, a);
    b >>= 1;
  }
  return res;
}
inline long long Inv(long long a) { return Pow(a, P - 2); }
long long Case, n, m, k;
signed main() {
  Case = read();
  while (Case--) {
    n = read(), m = read(), k = read();
    if ((m > n * (n - 1) / 2) || m < n - 1) {
      puts("NO");
      continue;
    }
    if (n == 1 && m == 0 && k > 1) {
      puts("YES");
      continue;
    }
    if (k > 3) {
      puts("YES");
      continue;
    }
    if (k == 3) {
      if (m == n * (n - 1) / 2)
        puts("YES");
      else
        puts("NO");
      continue;
    }
    if (k == 2) {
      if (n == 1)
        puts("YES");
      else
        puts("NO");
      continue;
    }
    puts("NO");
  }
  return 0;
}
