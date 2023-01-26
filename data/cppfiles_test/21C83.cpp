#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, M = 200200;
bool s[M];
long long n, ans, x[M], y[M], f[M], sum[M];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld %lld", &x[i], &y[i], &s[i]);
    f[i] = (x[i] - y[i] + sum[i - 1] + mod -
            sum[lower_bound(x + 1, x + 1 + i, y[i]) - x - 1]) %
           mod;
    ans += s[i] ? f[i] : 0;
    sum[i] = (sum[i - 1] + f[i]) % mod;
  }
  printf("%lld\n", (ans + x[n] + 1) % mod);
  return 0;
}
