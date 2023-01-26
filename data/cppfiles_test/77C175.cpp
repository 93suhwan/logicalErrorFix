#include <bits/stdc++.h>
using namespace std;
int n, mod;
const int nax = 4e6 + 5;
long long int dp[nax];
long long int pref[nax];
void solve() {
  cin >> n >> mod;
  dp[n] = 1;
  pref[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = pref[i + 1];
    for (int mul = 2; mul * i <= n; mul++) {
      int LO = i * mul;
      int HI = min(n, LO + mul - 1);
      long long int sum = pref[LO] - pref[HI + 1];
      dp[i] += sum;
      dp[i] %= mod;
    }
    pref[i] = pref[i + 1] + dp[i];
    pref[i] %= mod;
  }
  cout << dp[1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while (tt--) solve();
  return 0;
}
