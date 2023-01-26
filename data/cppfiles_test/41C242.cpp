#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1E9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int gcd_ex(long long int a, long long int b, long long int& x,
                     long long int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int g = gcd_ex(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}
long long int multi_mod_inv(long long int a, long long int m) {
  long long int x, y;
  long long int g = gcd_ex(a, m, x, y);
  if (g != 1) {
    return -1;
  }
  x = (x % m + m) % m;
  return x;
}
long long int mod_div(long long int a, long long int b, long long int m) {
  if (multi_mod_inv(b, m) != -1) {
    return (a % m * multi_mod_inv(b, m) % m) % m;
  } else {
    return -1;
  }
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int p = power(a, n / 2);
  p = (p * p) % MOD;
  if (n % 2)
    return (p * a) % MOD;
  else
    return p % MOD;
}
string temp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int test_case = 1;
  for (long long int test = 1; test <= test_case; test++) {
    long long int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    temp.push_back('c');
    for (long long int i = 0; i < n; i++) {
      temp.push_back('a');
      temp.push_back('b');
      temp.push_back('c');
    }
    long long int dp[6][n + 1];
    memset(dp, 0, sizeof(dp));
    for (long long int i = 0; i < 3; i++) {
      for (long long int j = 0; j < n; j++) {
        dp[i][j + 1] = dp[i][j];
        if (temp[j + i] != s[j]) {
          dp[i][j + 1]++;
        }
      }
    }
    reverse(temp.begin(), temp.end());
    for (long long int i = 3; i < 6; i++) {
      for (long long int j = 0; j < n; j++) {
        dp[i][j + 1] = dp[i][j];
        if (temp[j + (i - 3)] != s[j]) {
          dp[i][j + 1]++;
        }
      }
    }
    while (m--) {
      long long int l, r;
      cin >> l >> r;
      long long int ans = 1E9;
      for (long long int i = 0; i < 6; i++) {
        ans = min(ans, dp[i][r] - dp[i][l - 1]);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
