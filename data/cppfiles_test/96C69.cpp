#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
void print(vector<long long> a) {
  for (long long i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
bool cmp(long long a, long long b) { return a > b; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, x;
  cin >> n >> x;
  vector<vector<long long> > dp(n + 1, vector<long long>(x + 1, 0)),
      dp1(n + 1, vector<long long>(n + 1, 0));
  long long m = 998244353;
  for (long long i = 0; i < x + 1; i++) dp[1][i] = i;
  for (long long i = 0; i < n + 1; i++) dp[i][1] = 1;
  dp[0][0] = 0;
  for (long long i = 0; i < n; i++) dp1[i + 1][0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j < i; j++) {
      dp1[i][j] = (dp1[i - 1][j - 1] + dp1[i - 1][j]);
      dp1[i][j] %= m;
    }
    dp1[i][i] = 1;
  }
  for (long long i = 2; i <= n; i++) {
    for (long long j = 2; j <= x; j++) {
      if (j + 1 <= i) {
        dp[i][j] = power(j, i, m);
        continue;
      }
      dp[i][j] = power(i - 1, i, m);
      for (long long k = 2; k <= i; k++) {
        long long l = dp1[i][k];
        long long h = power(i - 1, i - k, m) * dp[k][j - i + 1];
        h = (h + m) % m;
        h = (h * l);
        h = (h + m) % m;
        dp[i][j] += h;
        dp[i][j] %= m;
      }
    }
  }
  cout << dp[n][x];
}
