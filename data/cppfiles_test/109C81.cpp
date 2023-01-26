#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, ans = 1, fac[200010];
char s[100010][2];
int power(int x, int y) {
  int t = 1;
  while (y) {
    if (y & 1) t = 1ll * t * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return t;
}
int inv(int x) { return power(x, mod - 2); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) cin >> s[i];
  int cnt = 0, cntb = 0, flagb = 1, flagw = 1;
  fac[0] = 1;
  for (int i = 1; i <= 2 * n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 1; i <= n; i++) {
    cnt += (s[i][0] == '?') + (s[i][1] == '?');
    cntb += (s[i][0] == 'B') + (s[i][1] == 'B');
    if (s[i][0] == '?' && s[i][1] == '?')
      ans = ans * 2ll % mod;
    else if (s[i][0] == s[i][1])
      ans = 0;
    if (s[i][0] == 'W' || s[i][1] == 'B') flagb = 0;
    if (s[i][0] == 'B' || s[i][1] == 'W') flagw = 0;
  }
  if (cntb > n || cnt + cntb < n) {
    printf("0");
    return 0;
  }
  ans = (1ll * fac[cnt] * inv(fac[cnt - n + cntb]) % mod * inv(fac[n - cntb]) %
             mod -
         ans + mod) %
        mod;
  ans = (ans + flagb + flagw) % mod;
  printf("%d", ans);
  return 0;
}
