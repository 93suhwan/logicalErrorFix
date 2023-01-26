#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
vector<long long int> Fac(1, 1), Mod_Inv(1, 1);
int Last_Index = 0;
long long int nCr(long long int n, long long int r, long long int m) {
  if (n < 0 || r < 0) return 0;
  if (r > n) return 0;
  if (n > Last_Index) {
    for (long long int i = Last_Index + 1; i <= n; ++i) {
      Fac.push_back(Fac[i - 1] * i);
      Fac[i] %= m;
      Mod_Inv.push_back(power(Fac[i], m - 2, m));
    }
    Last_Index = n;
  }
  return (((Fac[n] * Mod_Inv[r]) % m) * Mod_Inv[n - r]) % m;
}
long long int gcd(long long int a, long long int b) {
  return (b ? gcd(b, a % b) : a);
}
int Google_Test;
void solve() {
  long long int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<long long int> dp(n);
  dp[0] = (s[0] == '+' ? 1 : -1);
  for (long long int i = 1; i < n; ++i) {
    if (i % 2)
      dp[i] = (s[i] == '+' ? -1 : 1);
    else
      dp[i] = s[i] == '+' ? 1 : -1;
    dp[i] += dp[i - 1];
  }
  while (q--) {
    long long int l, r;
    cin >> l >> r;
    long long int t = (r - l + 1);
    if ((l == 1 && dp[r - 1] == 0) || dp[r - 1] - dp[l - 2] == 0)
      cout << 0 << '\n';
    else
      cout << 2 - t % 2 << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
