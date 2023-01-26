#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
bool remender(long long a, long long b) { return a % b; }
vector<long long> fact;
long long add(long long x, long long y) { return (x + y) % mod; }
long long multi(long long x, long long y) { return (x * y) % mod; }
void fac(int n) {
  fact.push_back(1);
  for (long long i = 1; i <= n; i++) {
    fact.push_back(multi(i, fact.back()));
  }
}
long long power(long long x, long long y) {
  x %= mod;
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = multi(res, x);
    y = y >> 1;
    x = multi(x, x);
  }
  return res;
}
long long inverse(long long n) { return power(n, mod - 2); }
long long nCr(int n, int r) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (multi(fact[n], multi(inverse(fact[r]), inverse(fact[n - r])))) % mod;
}
long long nPr(long long n, long long r) { return power(n, r) % mod; }
void solve() {
  long long n, x;
  cin >> n >> x;
  fac(600);
  long long dp[x + 5][n + 3];
  memset(dp, 0, sizeof dp);
  for (int i = 2; i <= x; i++) {
    for (int j = 2; j <= n; j++) {
      if (i <= j) {
        long long rem = i - 1;
        long long c = nPr(rem, j);
        dp[i][j] = c;
      } else {
        for (int k = 2; k <= j; k++) {
          long long chosen = j - k;
          long long places = j;
          long long c = nPr(places, chosen);
          dp[i][j] = add(dp[i][j], multi(c, dp[i - j][k]));
        }
      }
    }
  }
  long long ans = nPr(min(x, n - 1), n);
  for (int i = n; i <= x; i++) {
    for (int k = 2; k <= n; k++) {
      ans = add(ans, multi(nCr(n, k), nPr(i - 1, n - k)));
    }
    ans = add(ans, multi(n, dp[i][n - 1]));
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
