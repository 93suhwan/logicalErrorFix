#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long mod = 998244353;
long long jc[N], jcny[N];
long long fp(long long x, long long y) {
  long long res = 1;
  while (y) res = (y & 1) ? res * x % mod : res, x = x * x % mod, y >>= 1;
  return res;
}
long long com(long long x, long long y) {
  return (((jc[x] * jcny[y]) % mod) * jcny[x - y]) % mod;
}
long long n, cnt1, cnt2, cnt3, cnt4, msk1, msk2;
int main() {
  jc[0] = 1;
  for (int i = 1; i < N; i++) {
    jc[i] = (jc[i - 1] * i) % mod;
  }
  for (int i = 0; i < N; i++) {
    jcny[i] = fp(jc[i], mod - 2);
  }
  scanf("%lld\n", &n);
  long long res = 1, wb = 1, bw = 1;
  for (int i = 1; i <= n; i++) {
    char s, ss;
    if ((s = getchar()) == 'W') cnt1++, msk1 |= 1;
    if (s == 'B') cnt2++, msk1 |= 2;
    if ((ss = getchar()) == 'W') cnt4++, msk2 |= 1;
    if (ss == 'B') cnt3++, msk2 |= 2;
    if (s != '?' && s == ss) res = 0;
    if (s == '?' && ss == s) res *= 2;
    res %= mod;
    if (s == 'W' || ss == 'B') wb = 0;
    if (s == 'B' || ss == 'W') bw = 0;
    getchar();
  }
  long long ans = wb + bw;
  for (int i = max(cnt1, cnt3); i <= n - max(cnt2, cnt4); i++) {
    ans +=
        (com(n - cnt1 - cnt2, i - cnt1) * com(n - cnt3 - cnt4, i - cnt3)) % mod;
    ans %= mod;
  }
  printf("%lld", ans - res);
  return 0;
}
