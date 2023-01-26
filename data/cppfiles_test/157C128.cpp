#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
char s[5005];
long long f[5005], iv[5005], a[5005], l, ans = 1;
long long pw(long long a, long long b) {
  long long r = 1;
  for (; b; b >>= 1, a = a * a % 998244353)
    if (b & 1) r = r * a % 998244353;
  return r;
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  return f[n] * iv[m] % 998244353 * iv[n - m] % 998244353;
}
signed main() {
  f[0] = 1;
  for (long long i = (1); i <= (5005 - 1); i++) f[i] = f[i - 1] * i % 998244353;
  iv[5005 - 1] = pw(f[5005 - 1], 998244353 - 2);
  for (long long i = (5005 - 2); i >= (0); i--)
    iv[i] = iv[i + 1] * (i + 1) % 998244353;
  long long n = read(), k = read();
  scanf("%s", s + 1);
  for (long long i = (1); i <= (strlen(s + 1)); i++)
    if (s[i] == '1') a[++l] = i;
  if (k == 0 || l < k) {
    puts("1");
    return 0;
  }
  a[l + 1] = n + 1;
  for (long long i = (k); i <= (l); i++) {
    long long p = i - k + 1, d = a[i + 1] - a[p - 1] - 2;
    if (i != l)
      ans += (C(a[i + 1] - a[p - 1] - 1, k) - C(a[i + 1] - a[p], k) +
              C(a[i + 1] - a[p] - 1, k) + 998244353) %
             998244353;
    else
      ans += (C(d + 1, k) + 998244353 - 1) % 998244353;
    ans %= 998244353;
  }
  printf("%lld\n", ans);
  return 0;
}
