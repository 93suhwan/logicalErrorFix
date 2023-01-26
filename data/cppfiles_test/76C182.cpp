#include <bits/stdc++.h>
using namespace std;
long long mod = pow(10, 9) + 7;
int _1 = 0;
long long suml(vector<long long> a, long long start = 0) {
  long long c = 0;
  long long i;
  for (i = start; i < a.size(); i++) {
    c += a[i];
  }
  return (c);
}
int main() {
  long long q, t, ans, i, j, n, _, type, k, u, a, b, x, m, y;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  long long pre = 1;
  for (i = 2; i <= n; i++) {
    dp[i] += pre;
    dp[i] = dp[i] % m;
    x = i;
    while (x >= 2) {
      y = i / x + 1;
      b = i / y;
      dp[i] += dp[i / x] * (x - b);
      dp[i] %= m;
      x = b;
    }
    pre += dp[i];
    pre = pre % m;
  }
  cout << dp[n] << '\n';
  ;
}
