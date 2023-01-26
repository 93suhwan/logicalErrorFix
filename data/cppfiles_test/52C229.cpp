#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int T, n, k;
long long ans, p;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    ans = 0;
    p = 1;
    for (int i = 0; i <= 31; i++) {
      if (((long long)(1 << i) & k) != 0) ans = (ans + p) % MOD;
      p = p * n % MOD;
    }
    printf("%lld\n", ans);
  }
}
