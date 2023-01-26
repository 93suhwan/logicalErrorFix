#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9;
FILE* stream;
mt19937 rng(1337);
long long n, m;
void solve() {
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  for (long long j = 2; j * 2 <= n; j++) {
    dp[j * 2] += dp[2] - dp[2 - 1];
    dp[j * 2] %= m;
  }
  for (long long i = 3; i <= n; i++) {
    dp[i] += dp[i - 1] * 2 + 1;
    dp[i] %= m;
    for (long long j = 2; j * i <= n; j++) {
      dp[j * i] += dp[i] - dp[i - 1];
      dp[j * i] %= m;
    }
  }
  cout << (dp[n] + m) % m << endl;
  return;
}
void solve1() {
  vector<long long> dp(n + 1);
  dp[n] = 1;
  long long all = 0;
  for (long long i = n; i >= 1; i--) {
    dp[i] += all;
    dp[i] %= m;
    all += dp[i];
    all %= m;
    long long j = 1;
    while (j * j < i) {
      dp[j] += (i / j - i / (j + 1)) * dp[i];
      dp[j] %= m;
      if (j != 1 && i / j != j) dp[i / j] += dp[i];
      dp[i / j] %= m;
      j++;
    }
    if (j != 1 && j * j == i) {
      dp[j] += dp[i];
      dp[j] %= m;
    }
  }
  cout << dp[1] << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  solve();
  return 0;
}
