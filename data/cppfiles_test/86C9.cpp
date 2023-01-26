#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXB = 10000000, INV2 = (MOD + 1) / 2;
int ppw[10000005], prp[10000005], pinv[10000005];
int power(int x, int t) {
  int ret = 1;
  while (t > 0) {
    if (t & 1) ret = 1ULL * ret * x % MOD;
    x = 1ULL * x * x % MOD;
    t >>= 1;
  }
  return ret;
}
int n, k, x;
void solve() {
  scanf("%d%d%d", &n, &k, &x);
  if (x == 0) {
    if (n > k) {
      printf("0\n");
      return;
    }
    int ret = 1ULL * prp[k] * pinv[k - n] % MOD;
    for (int i = 0; i < (int)(n); i++) ret = 1ULL * ret * ppw[i] % MOD;
    printf("%d\n", ret);
  } else {
    int ret = 0, ccf = 1, tmp = power(2, n);
    for (int i = 0; i <= k; i++) {
      int prob =
          i == 0
              ? 1
              : (1 + 1ULL * pinv[k] * prp[k - 1] % MOD * (MOD - ppw[i] + 1)) %
                    MOD;
      ret = (ret + 1ULL * ccf * pinv[i] % MOD * prob) % MOD;
      ccf = 1ULL * ccf * (tmp - 1) % MOD * (ppw[k - i] - 1) % MOD;
      tmp = 1ULL * tmp * INV2 % MOD;
      ccf = 1ULL * ccf * ppw[i] % MOD;
    }
    printf("%d\n", ret);
  }
}
int main() {
  ppw[0] = 1;
  for (int i = 1; i <= (int)(MAXB); i++) ppw[i] = 2 * ppw[i - 1] % MOD;
  prp[0] = 1;
  for (int i = 1; i <= (int)(MAXB); i++)
    prp[i] = 1ULL * prp[i - 1] * (ppw[i] - 1) % MOD;
  pinv[MAXB] = power(prp[MAXB], MOD - 2);
  for (int i = MAXB; i >= 1; i--)
    pinv[i - 1] = 1ULL * pinv[i] * (ppw[i] - 1) % MOD;
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
