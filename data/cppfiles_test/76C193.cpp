#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 5, mod = 1e9 + 7, mxN = 1e5 + 5;
long long dp[N], pf[N];
void solve() {
  long long n, m;
  cin >> n >> m;
  dp[1] = pf[1] = 1;
  for (long long i = 1; i <= n; i++) {
    dp[i] += pf[i - 1];
    long long root = sqrt(i);
    for (long long k = 2; i / k > root; k++) dp[i] += dp[i / k], dp[i] %= m;
    for (long long k = 1; k * k <= i and i > 1; k++) {
      long long lo = i / (k + 1) + 1, hi = i / k;
      dp[i] += (hi - lo + 1) * dp[k] % m;
      dp[i] %= m;
    }
    pf[i] = pf[i - 1] + dp[i];
    pf[i] %= m;
  }
  cout << dp[n] << ' ';
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long T = 1;
  for (long long i = 1; i <= T; i++) {
    solve();
  }
  cerr << clock() << '\n';
}
