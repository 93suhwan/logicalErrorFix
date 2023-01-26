#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int mul(long long int a, long long int b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long int add(long long int a, long long int b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long int sub(long long int a, long long int b) {
  return (((a + mod) % mod) - ((b + mod) % mod) + mod) % mod;
}
long long int po(long long int a, long long int b) {
  if (b == 0) {
    return 1;
  }
  long long int t = po(a, b / 2);
  if (b % 2) {
    return mul(t, mul(t, a));
  } else {
    return mul(t, t);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(12);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    long long int dp[n + 1];
    dp[0] = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '+') {
        dp[i + 1] = dp[i] + pow(-1, i);
      } else {
        dp[i + 1] = dp[i] - pow(-1, i);
      }
    }
    while (q--) {
      long long int l, r;
      cin >> l >> r;
      long long int x = abs(dp[r] - dp[l - 1]);
      if (x == 0) {
        cout << "0\n";
        continue;
      }
      if (x % 2) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
    }
  }
  return 0;
}
