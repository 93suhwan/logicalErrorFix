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
void cal(vector<long long int> &v, string &s, long long int n,
         long long int st) {
  vector<long long int> dp(n);
  dp[st] = n - st;
  long long int L, R;
  L = R = st;
  for (long long int i = st + 1; i < n; ++i) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R] == s[R - L + st]) ++R;
      dp[i] = R - L;
      if (R < n) {
        if (s[R] > s[st + R - L]) v[i] = n - R;
      }
      R--;
    } else {
      long long int k = i - L + st;
      if (i + dp[k] <= R) {
        dp[i] = dp[k];
        if (v[k] != -1) v[i] = v[k] - i + k;
      } else {
        L = i;
        R++;
        while (R < n && s[R - L + st] == s[R]) R++;
        dp[i] = R - L;
        if (R < n) {
          if (s[R] > s[st + R - L]) v[i] = n - R;
        }
        R--;
      }
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<long long int>> pre(n, vector<long long int>(n, -1));
  for (long long int i = 0; i < n; ++i) cal(pre[i], s, n, i);
  vector<long long int> dp(n);
  long long int ans = 0;
  for (long long int i = 0; i < n; ++i) {
    dp[i] = n - i;
    for (long long int j = 0; j < i; ++j) {
      if (pre[j][i] != -1) dp[i] = max(dp[i], dp[j] + pre[j][i]);
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
