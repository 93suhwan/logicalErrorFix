#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 100;
long long n, q, a[N], s[N], p[N];
inline void add(long long &a, long long b) {
  a = ((a + b >= 1000000007) ? a + b - 1000000007 : a + b);
}
inline void del(long long &a, long long b) {
  a = ((a - b < 0) ? a - b + 1000000007 : a - b);
}
inline void mul(long long &a, long long b) { a = a * b % 1000000007; }
inline long long m_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) mul(ans, a);
    b >>= 1;
    mul(a, a);
  }
  return ans;
}
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
long long cal(long long n) {
  static long long iv = m_pow(6, 1000000007 - 2);
  return n * (n + 1) % 1000000007 * (2 * n + 1) % 1000000007 * iv % 1000000007;
}
signed main() {
  n = read();
  q = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    s[i] = s[i - 1];
    p[i] = p[i - 1];
    add(s[i], a[i]);
    add(p[i], a[i] * a[i] % 1000000007);
  }
  while (q--) {
    long long l = read(), r = read(), D = read(), S, P, x, y, len = r - l + 1;
    S = (s[r] - s[l - 1] + 1000000007) % 1000000007;
    del(S, len * a[l] % 1000000007);
    mul(S, m_pow(D, 1000000007 - 2));
    P = (p[r] - p[l - 1] + 1000000007) % 1000000007;
    del(P, 2 * a[l] * (s[r] - s[l - 1] + 1000000007) % 1000000007);
    add(P, len * a[l] % 1000000007 * a[l] % 1000000007);
    mul(P, m_pow(D * D % 1000000007, 1000000007 - 2));
    x = (2 * S % 1000000007 - len * (len - 1) % 1000000007 + 1000000007) *
        m_pow(2 * len % 1000000007, 1000000007 - 2) % 1000000007;
    if (x < 1000000007 - len + 1 && x != 0) {
      printf("No\n");
      continue;
    }
    y = len - (1000000007 - x) % 1000000007 - 1;
    x = 1000000007 - x;
    x %= 1000000007;
    del(P, cal(x));
    del(P, cal(y));
    if (P == 0)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
