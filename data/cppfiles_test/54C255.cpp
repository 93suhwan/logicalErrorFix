#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MAXN = 2e5 + 100;
int fact[MAXN];
int add(int a, int b) { return (a + b) % mod; }
int mult(int a, int b) { return (a % mod) * (b % mod) % mod; }
int gcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return 1;
  }
  int x1, y1;
  int ans = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return ans;
}
int modInverse(int a) {
  int x, y;
  int g = gcd(a, mod, x, y);
  if (g != 1) {
    return -1;
  } else {
    x = (x % mod + mod) % mod;
    return x;
  }
}
int nCr(int n, int r) {
  if (r > n) return 0;
  if (!r || r == n) return 1;
  return mult(fact[n], modInverse(mult(fact[n - r], fact[r])));
}
int binpow(long long n, long long k) {
  if (k == 0) return 1;
  if (k % 2 == 0)
    return (binpow(n, k / 2) % mod) * (binpow(n, k / 2) % mod) % mod;
  long long tmp = binpow(n, k - 1) % mod;
  return (tmp % mod) * (n % mod) % mod;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  int all = binpow(2, n);
  int even = binpow(2, n - 1);
  if (n % 2 == 1) {
    cout << binpow(even + 1, k) << '\n';
    return;
  }
  if (k == 0) {
    cout << 1 << '\n';
    return;
  }
  vector<vector<int>> dp(k + 1, vector<int>(2));
  dp[1][1] = 1;
  dp[1][0] = even - 1;
  for (int i = 2; i < k + 1; i++) {
    dp[i][0] = mult(dp[i - 1][0], even - 1);
    dp[i][1] = add(dp[i - 1][0], mult(dp[i - 1][1], all));
  }
  cout << add(dp[k][1], dp[k][0]) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mult(fact[i - 1], i);
  }
  int t = 1;
  cin >> t;
  while (t--) solve();
}
