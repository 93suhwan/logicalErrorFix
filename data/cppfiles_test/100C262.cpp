#include <bits/stdc++.h>
using namespace std;
int w[200005];
const int mod = 998244353;
signed main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1);
    if (w[n] == w[n - 1]) {
      long long ans = 1;
      for (long long i = 2; i <= n; i++) {
        ans *= i;
        ans %= mod;
      }
      printf("%lld\n", ans);
      continue;
    }
    if (w[n] - w[n - 1] != 1) {
      puts("0");
      continue;
    }
    int pp = n - 1;
    while (w[pp] == w[n]) pp--;
    long long op1 = 0;
    for (int i = 1; i <= n; i++) {
      if (w[i] == w[pp]) {
        op1++;
      }
    }
    long long ans = op1;
    for (long long i = 2; i <= op1; i++) {
      ans *= i;
      ans %= mod;
    }
    for (long long i = 1; i <= (n - op1 - 1); i++) {
      ans *= (op1 + 2 + i - 1);
      ans %= mod;
    }
    printf("%lld\n", ans);
  }
}
