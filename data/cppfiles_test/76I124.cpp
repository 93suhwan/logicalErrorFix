#include <bits/stdc++.h>
using namespace std;
long long dp[200005];
long long c_dp[200005];
void solve(long long tc) {
  long long n, m;
  cin >> n >> m;
  dp[1] = 1;
  c_dp[1] = 1;
  for (long long i = 2; i <= n; i++) {
    long long lo = 1;
    long long hi = 3ll * ceil(sqrt(i));
    for (long long j = 1; j <= hi; j++) {
      long long l = i / (j + 1) + 1;
      long long r = i / j;
      if (l == 1) l++;
      long long c = max((r - l + 1), 0ll);
      dp[i] = (dp[i] + c * dp[j]) % m;
    }
    dp[i] += c_dp[i - 1];
    dp[i] %= m;
    c_dp[i] = (c_dp[i - 1] + dp[i]) % m;
  }
  cout << dp[n];
}
int main() {
  ios_base::sync_with_stdio(0);
  long long t = 1;
  long long tc = 1;
  while (t--) {
    solve(tc);
    tc++;
  }
  return 0;
}
