#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5, MAXM = 1e6 + 5, MAXF = 1e1;
const int INF = 2e9;
const int mod = 1e9 + 7;
int t, n;
long long dp[MAXN];
int main() {
  cin >> t;
  for (int fi = 0; fi <= 2e5; fi++) {
    dp[fi] = (fi > 2 ? (dp[fi - 1]) % mod * (fi % mod) : 1);
    dp[fi] %= mod;
  }
  while (t--) {
    cin >> n;
    cout << dp[2 * n] << '\n';
  }
}
