#include <bits/stdc++.h>
using namespace std;
int n, mo;
long long f[4000004], sum[4000004];
int main() {
  scanf("%d%d", &n, &mo);
  f[n] = sum[n] = 1;
  for (int i = n - 1; i; i--) {
    f[i] += sum[i + 1];
    for (int j = 2; i * j <= n; j++)
      f[i] += ((sum[i * j] - sum[min(i * j + j, n + 1)]) % mo + mo) % mo,
          f[i] %= mo;
    sum[i] = (sum[i + 1] + f[i]) % mo;
  }
  printf("%lld\n", (f[1] % mo + mo) % mo);
  return 0;
}
