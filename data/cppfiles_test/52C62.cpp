#include <bits/stdc++.h>
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long ans = 0, b = 1;
    while (k) {
      if (k & 1) ans = (ans + b) % 1000000007ll;
      k >>= 1;
      b = (b * n) % 1000000007ll;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
