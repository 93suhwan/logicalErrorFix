#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 4000005;
int n, m;
ll dp[maxn];
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  dp[1] = 1;
  dp[2] = 2;
  for (ll x = 3; x <= n; x++) {
    dp[x] = (dp[x] + dp[x - 1] + dp[1] + dp[x - 1]) % m;
    for (int c = 2 * (x - 1); c <= n; c += x - 1) {
      dp[c] += dp[x - 1] - dp[x - 2] + m;
      dp[c] %= m;
    }
  }
  cout << dp[n] << endl;
  return 0;
}
