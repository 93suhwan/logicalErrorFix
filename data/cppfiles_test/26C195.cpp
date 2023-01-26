#include <bits/stdc++.h>
long long ans[200005];
int main() {
  int n, x;
  ans[1] = 1, ans[2] = 1;
  for (int i = 3; i <= 200000; ++i) ans[i] = ans[i - 1] * i % 1000000007;
  for (scanf("%d", &n); n; --n) {
    scanf("%d", &x);
    printf("%lld\n", ans[2 * x]);
  }
  return 0;
}
