#include <bits/stdc++.h>
using namespace std;
long long orz = 998244353LL;
int a[200005];
long long fac[200005] = {1, 1}, inv[200005] = {1, 1}, f[200005] = {1, 1};
void genfact() {
  for (int i = 2; i < 200005; i++) {
    fac[i] = fac[i - 1] * i % orz;
    f[i] = (orz - orz / i) * f[orz % i] % orz;
    inv[i] = inv[i - 1] * f[i] % orz;
  }
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  return fac[n] * inv[m] % orz * inv[n - m] % orz;
}
int main() {
  int T, i, n, j;
  long long ans, cnt, sub;
  scanf("%d", &T);
  genfact();
  while (T--) {
    scanf("%d", &n);
    ans = fac[n];
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (i = n - 1, cnt = 0; i >= 0; i--) {
      if (a[i] == a[n - 1]) cnt++;
    }
    if (cnt > 1) {
      printf("%lld\n", ans);
      continue;
    }
    for (i = 0, cnt = 0; i < n; i++) {
      if (a[i] == a[n - 1] - 1) cnt++;
    }
    sub = ((C(n, cnt + 1) * fac[cnt] % orz) * fac[n - cnt - 1]) % orz;
    ans = (ans + orz - sub) % orz;
    printf("%lld\n", ans);
  }
  return 0;
}
