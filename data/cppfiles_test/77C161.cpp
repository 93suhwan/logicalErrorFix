#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 100;
int mod;
long long dp[N], sum[N];
void solve() {
  int n;
  cin >> n >> mod;
  dp[n] = 1;
  sum[n] = 1;
  sum[n + 1] = 0;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = sum[i + 1];
    for (int j = i + i; j <= n; j += i) {
      dp[i] = (dp[i] + sum[j] - sum[min(j + j / i - 1, n) + 1] + mod) % mod;
    }
    sum[i] = (dp[i] + sum[i + 1]) % mod;
  }
  cout << dp[1] % mod << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
