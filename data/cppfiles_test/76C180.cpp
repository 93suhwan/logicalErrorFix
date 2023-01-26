#include <bits/stdc++.h>
using namespace std;
long long a[4000005], sum[4000005];
int main() {
  long long n, mod;
  scanf("%lld%lld", &n, &mod);
  a[1] = sum[1] = 1;
  long long add = 0;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 2; j * j <= i; j++)
      if (i % j == 0) {
        add = (add + a[j] - a[j - 1]) % mod;
        if (i != j * j) add = (add + a[i / j] - a[i / j - 1]) % mod;
      }
    add = (add + a[1]) % mod;
    a[i] = (sum[i - 1] + add) % mod;
    sum[i] = (sum[i - 1] + a[i]) % mod;
  }
  printf("%lld\n", (a[n] + mod) % mod);
  return 0;
}
