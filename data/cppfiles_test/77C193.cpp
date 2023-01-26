#include <bits/stdc++.h>
using namespace std;
int n;
long long MOD;
long long cha[4000005];
long long ans[4000005];
int main() {
  scanf("%d%lld", &n, &MOD);
  cha[1] = 1;
  cha[2] = -1;
  ans[1] = 1;
  for (int i = 1; i <= n; i++) {
    if (i != 1) {
      ans[i] = ((cha[i] + ans[i - 1]) % MOD + MOD) % MOD;
    }
    for (int j = i * 2, k = 1; j <= n; j = j + i, k++) {
      cha[j] = (cha[j] + ans[i]) % MOD;
      cha[min(j + k, n) + 1] =
          ((cha[min(j + k, n) + 1] - ans[i]) % MOD + MOD) % MOD;
    }
    cha[i + 1] = (cha[i + 1] + ans[i]) % MOD;
  }
  printf("%lld\n", ans[n]);
  return 0;
}
