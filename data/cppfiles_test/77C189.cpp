#include <bits/stdc++.h>
using namespace std;
long long n, MOD, f[(long long)4e6 + 5], sum[(long long)4e6 + 5],
    d[(long long)4e6 + 5];
signed main() {
  cin >> n >> MOD;
  long long Sum = 0;
  for (long long i = 1; i <= n; i++) {
    if (i == 1)
      f[1] = 1;
    else
      f[i] = (Sum + d[i] + sum[i - 1]) % MOD;
    sum[i] = (sum[i - 1] + f[i]) % MOD;
    for (long long j = 1; j * i <= n; j++) {
      d[j * i] = (d[j * i] + f[i]) % MOD;
      if (j * i + j <= n) d[j * i + j] = (d[j * i + j] - f[i] + MOD) % MOD;
    }
    Sum = (Sum + d[i]) % MOD;
  }
  cout << f[n] % MOD;
  return 0;
}
