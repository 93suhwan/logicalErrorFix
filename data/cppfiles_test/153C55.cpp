#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
const ll MOD = 998244353;
using str = array<int, 26>;
ll count(const str& s) {
  ll ways = 1;
  for (int i = 0; i < 26; i++) ways = ways * (s[i] + 1) % MOD;
  return ways;
}
void solve() {
  int n;
  cin >> n;
  vector<str> a(n, str{});
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) a[i][c - 'a']++;
  }
  vector<ll> dp(1 << n);
  for (int mask = 1; mask < (1 << n); mask++) {
    str here{};
    bool flip = 0;
    for (int j = 0; j < 26; j++) here[j] = 1e9;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i)) {
        flip = !flip;
        for (int j = 0; j < 26; j++) here[j] = min(here[j], a[i][j]);
      }
    dp[mask] = count(here);
    if (!flip) (dp[mask] = MOD - dp[mask]) % MOD;
  }
  for (int i = 0; i < n; i++)
    for (int mask = 0; mask < (1 << n); mask++)
      if (mask & (1 << i)) dp[mask] = (dp[mask] + dp[mask ^ (1 << i)]) % MOD;
  ll ans = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    int k = 0;
    int idxSum = 0;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i)) {
        k++;
        idxSum += i + 1;
      }
    ans ^= k * idxSum * dp[mask];
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  solve();
  return 0;
}
