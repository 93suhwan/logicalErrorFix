#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const long long S = 4000008;
long long n, p;
long long dp[S], f[S];
long long qnum(long long k) {
  long long ans = 1, i = 2;
  for (; i * i < k; i++) {
    if (k % i == 0) {
      ans = (ans + (((dp[k / i] + f[k / i]) % p -
                     (dp[k / i - 1] + f[k / i - 1]) % p + p) %
                        p +
                    ((dp[i] + f[i]) % p - (dp[i - 1] + f[i - 1]) % p + p) % p) %
                       p) %
            p;
    }
  }
  if (i * i == k)
    ans = (ans + ((dp[i] + f[i]) % p - (dp[i - 1] + f[i - 1]) % p + p) % p) % p;
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin >> n >> p;
  long long sum = 1;
  dp[1] = 1;
  f[1] = 0;
  for (long long i = 2; i <= n; i++) {
    dp[i] = sum;
    f[i] = (f[i - 1] + qnum(i)) % p;
    sum = (sum + (dp[i] + f[i]) % p) % p;
  }
  cout << (dp[n] + f[n]) % p << endl;
  return 0;
}
