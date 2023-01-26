#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long int dp[N];
long long int n, mod;
int main() {
  cin >> n >> mod;
  dp[1] = 1;
  long long int sum = dp[1], cnt;
  for (int i = 2; i <= n; i++) {
    dp[i] = (dp[i] + sum) % mod;
    cnt = 0;
    for (int l = 2, r; l <= i; l = r + 1) {
      r = i / (i / l);
      cnt = (cnt % mod + (r - l + 1) * dp[i / l] % mod) % mod;
    }
    dp[i] = (dp[i] + cnt) % mod;
    sum = (sum + dp[i]) % mod;
  }
  cout << dp[n] << endl;
}
