#include <bits/stdc++.h>
using namespace std;
long long n;
long long t1, t2, t3;
bool flag1, flag2, flag3;
char s[5];
long long mod = 998244353;
long long ksm(long long k, long long w) {
  long long sum = 1;
  while (w) {
    if (w % 2) {
      sum *= k;
      sum %= mod;
    }
    k *= k;
    k %= mod;
    w /= 2;
  }
  return sum;
}
long long jc[200005], ny[200005];
long long c(long long x, long long y) {
  return (((jc[x] * ny[y]) % mod) * ny[x - y]) % mod;
}
signed main() {
  jc[0] = 1;
  for (long long i = 1; i <= 200000; i++) {
    jc[i] = jc[i - 1] * i;
    jc[i] %= mod;
  }
  ny[200000] = ksm(jc[200000], mod - 2);
  for (long long i = 199999; i >= 0; i--) {
    ny[i] = (ny[i + 1] * (i + 1)) % mod;
  }
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    scanf("%s", s);
    if (s[0] == 'B') t1++;
    if (s[1] == 'B') t1++;
    if (s[0] == 'W') t2++;
    if (s[1] == 'W') t2++;
    if (s[0] == 'B' && s[1] == 'B') flag1 = 1;
    if (s[0] == 'W' && s[1] == 'W') flag1 = 1;
    if (s[0] == 'B' && s[1] == 'W') flag2 = 1;
    if (s[0] == 'B' && s[1] == '?') flag2 = 1;
    if (s[0] == '?' && s[1] == 'W') flag2 = 1;
    if (s[0] == 'W' && s[1] == 'B') flag3 = 1;
    if (s[0] == 'W' && s[1] == '?') flag3 = 1;
    if (s[0] == '?' && s[1] == 'B') flag3 = 1;
    if (s[0] == '?' && s[1] == '?') t3++;
  }
  if (t1 > n || t2 > n) {
    printf("0");
    return 0;
  }
  long long ans = c(2 * n - t1 - t2, n - t1);
  if (flag1) {
    printf("%lld", ans);
    return 0;
  }
  long long temp = ksm(2, t3);
  ans = (ans - temp + mod) % mod;
  if (!flag2) ans++;
  if (!flag3) ans++;
  printf("%lld", ans % mod);
  return 0;
}
