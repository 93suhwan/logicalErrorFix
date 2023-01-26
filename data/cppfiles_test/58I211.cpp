#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string str[2];
    cin >> str[0];
    cin >> str[1];
    long long int dp[2][n];
    memset(dp, 0, sizeof(dp));
    if (str[0][0] == '0') dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
      if (str[0][i] == '0') dp[0][i] = (dp[1][i - 1] + dp[0][i - 1]);
      if (str[1][i] == '0') dp[1][i] = (dp[1][i - 1] + dp[0][i - 1]);
    }
    if (dp[1][n - 1])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
