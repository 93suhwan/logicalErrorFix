#include <bits/stdc++.h>
using namespace std;
const int N = 4000010;
const long long mod = 998244353;
const double pi = 3.1415926535897932;
int n;
long long m;
long long dp[N], sum[N];
int main() {
  cin >> n >> m;
  dp[n] = 1, sum[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = sum[i + 1];
    for (int j = 2; i * j <= n; j++) {
      int r = min(n, i * j + j - 1);
      dp[i] = dp[i] + sum[i * j] - sum[r + 1];
      dp[i] += m;
      dp[i] %= m;
    }
    sum[i] = dp[i] + sum[i + 1];
  }
  cout << dp[1] << endl;
  return 0;
}
