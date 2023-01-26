#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline int read() {
  int x = 0;
  int f = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    f |= (ch == '-') ? 1 : 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
const int mod = 1e9 + 7;
int n, k, t;
inline long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  t = read();
  while (t--) {
    n = read();
    k = read();
    if (n & 1) {
      long long ans = qpow(2, n - 1) + 1;
      ans = qpow(ans, k);
      printf("%lld\n", ans);
    } else {
      long long ans = (qpow(2, n - 1) - 1 + mod) % mod;
      ans = qpow(ans, k);
      long long tmp = qpow(2, n);
      for (int i = 1; i <= k; ++i) ans = (ans + qpow(tmp, i - 1)) % mod;
      printf("%lld\n", ans);
    }
  }
}
