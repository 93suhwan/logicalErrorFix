#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, ans, temp, sum, m, l, r;
  string sans, s;
  t = 1;
  while (t--) {
    sans = "NO";
    ans = temp = sum = 0;
    cin >> n >> m;
    cin >> s;
    vector<vector<long long> > dp(3, vector<long long>(n + 5, 0));
    for (i = n - 1; i >= 0; i--) {
      for (j = 0; j <= 2; j++) dp[j][i] = dp[j][i + 3];
      dp[s[i] - 'a'][i]++;
    }
    vector<string> poss = {"abc", "acb", "bac", "bca", "cab", "cba"};
    while (m--) {
      cin >> l >> r;
      long long len = r - l + 1;
      ans = 0;
      l--;
      r--;
      if (len == 1) {
        cout << ans << "\n";
        continue;
      }
      if (len == 2) {
        if (s[l] == s[r]) ans++;
        cout << ans << "\n";
        continue;
      }
      ans = 9999999999999;
      for (string str : poss) {
        long long curr = 0;
        for (j = 0; j < 3; j++) {
          char ch = str[j];
          int num = (int)(ch - 'a');
          long long rem = (len - j) % 3;
          long long y;
          if (rem == 0)
            y = r + 1;
          else if (rem == 1)
            y = r + 3;
          else
            y = r + 2;
          long long cnt = dp[num][l + j] - dp[num][y];
          long long tot = ceil_div(len - j, 3);
          curr += tot - cnt;
        }
        ans = min(ans, curr);
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
