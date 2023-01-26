#include <bits/stdc++.h>
using namespace std;
long long int mod;
const long long int N = 2e5 + 5;
long long int fact[N], inv[N];
void cases() {
  long long int n;
  cin >> n >> mod;
  long long int dp[n + 1];
  dp[0] = 0;
  dp[1] = 1;
  long long int p = 1;
  for (long long int i = 2; i <= n; i++) {
    dp[i] = p;
    for (long long int j = 2; j * j < i; j++) {
      long long int val = i / j;
      if (val * val <= i) break;
      dp[i] = (dp[i] + dp[i / j]) % mod;
    }
    long long int k = 1;
    while (k * k <= i) {
      dp[i] = (dp[i] + ((i / k - i / (k + 1)) % mod * dp[k] % mod) % mod) % mod;
      k++;
    }
    p = (p + dp[i]) % mod;
  }
  cout << dp[n] << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    cases();
  }
}
