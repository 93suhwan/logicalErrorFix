#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
mt19937 rnd(179);
long long mod = 1000000007;
vector<pair<long long, long long>> P;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n >> mod;
  vector<long long> dp(n + 1);
  dp[1] = 1;
  long long su = 1;
  for (long long i = 2; i < n + 1; ++i) {
    dp[i] += su;
    dp[i] %= mod;
    long long j = 2;
    while (j <= i) {
      long long u = i / j;
      dp[i] += dp[u] * (i / u - j + 1);
      dp[i] %= mod;
      j = i / u + 1;
    }
    su += dp[i];
    su %= mod;
  }
  cout << dp[n] << '\n';
}
