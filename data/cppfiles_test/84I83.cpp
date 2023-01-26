#include <bits/stdc++.h>
using namespace std;
int b[500010], pr[500010], phi[500010], sz;
long long sp[500010];
int main() {
  int T, n, k;
  scanf("%d", &T);
  while (T--) {
    long long ans = 0;
    scanf("%d%d", &n, &k);
    if (!(n >> k)) {
      printf("%d\n", n);
      continue;
    }
    ans = n;
    for (int i = 1; i <= k - 1; i++) n = (n) >> 1;
    --n;
    int d = n / k, lst = n % k;
    ans +=
        1ll * (k - lst) * d * (d + 1) / 2 + 1ll * lst * (d + 1) * (d + 2) / 2;
    printf("%lld\n", ans);
  }
}
