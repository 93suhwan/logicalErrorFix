#include <bits/stdc++.h>
int main() {
  static int aa[200000], dp[200000 + 1], dq[200000], dr[200000], qu[200000];
  int n, i, cnt;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &aa[i]);
  dp[0] = n % 2 == 0 ? 1 : 998244353 - 1;
  cnt = 0;
  for (i = 0; i < n; i++) {
    int q = dp[i];
    while (cnt && aa[qu[cnt - 1]] >= aa[i]) {
      q = (q + dq[cnt - 1]) % 998244353;
      cnt--;
    }
    dq[cnt] = q, qu[cnt] = i,
    dr[cnt] = ((cnt == 0 ? 0 : dr[cnt - 1]) + (long long)q * aa[i]) % 998244353,
    cnt++;
    dp[i + 1] = (998244353 - dr[cnt - 1]) % 998244353;
  }
  printf("%d\n", dp[n]);
  return 0;
}
