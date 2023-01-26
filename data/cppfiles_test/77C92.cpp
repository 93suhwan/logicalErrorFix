#include <bits/stdc++.h>
using LL = long long;
using namespace std;
const int maxn = 8e6 + 5;
LL n, mod, dp[maxn], sum[maxn];
int main() {
  cin >> n >> mod;
  sum[n] = 1, dp[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = (dp[i] + sum[i + 1]) % mod;
    for (int j = 2; i * j <= n; j++) {
      dp[i] = (dp[i] + sum[i * j] - sum[(i + 1) * j]) % mod + mod;
      dp[i] %= mod;
    }
    sum[i] = (dp[i] + sum[i + 1]) % mod;
  }
  cout << (dp[1] + mod) % mod << endl;
  return 0;
}
