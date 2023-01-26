#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 8 * 1e18;
const int big = 1e6 + 7;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long p = mod) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res;
}
long long lcm(long long x, long long y) { return ((x * y) / (gcd(x, y))); }
long long modi(long long x, long long p = mod) { return power(x, p - 2, p); }
void solve() {
  int n;
  long long m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  long long sum = 1;
  for (int i = 2; i < n + 1; i++) {
    long long an = sum;
    int sq = sqrt(i);
    for (int j = 2; j < sq + 1; j++) (an += dp[i / j]) %= m;
    for (int j = 1; j < sq + 1; j++)
      (an += dp[j] * ((i / j) - (i / (j + 1)))) %= m;
    if ((i / sq) == sq) an -= dp[sq];
    (an += m) %= m;
    dp[i] = an;
    sum += an;
  }
  cout << dp[n] << endl;
}
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void preprocessing() {}
int main() {
  cout << setprecision(10);
  bool q = 0;
  fastio();
  int t = 1;
  if (q) cin >> t;
  preprocessing();
  while (t--) {
    solve();
  }
}
