#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 10;
long long n, m;
long long dp[maxn];
long long pr[maxn];
long long dd[maxn];
void solve() {
  cin >> n >> m;
  dp[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = (dp[i] + dp[i + 1]) % m;
    for (int j = 2; i * j <= n; j++) {
      long long o = min(n, 1LL * j * (i + 1) - 1);
      long long d = dp[i * j];
      if (o < n) d = (d - dp[j * (i + 1)] + m) % m;
      dp[i] = (dp[i] + d) % m;
    }
    dp[i] = (dp[i] + dp[i + 1]) % m;
  }
  cout << (dp[1] - dp[2] + m) % m << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
}
