#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long bp(long long a, long long b) {
  a %= 1000000007;
  long long res = 1;
  while (b > 0) {
    if (b % 2) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return res;
}
long long n;
const long long N = 1e4 + 1;
long long a[N];
bool f(long long r) {
  vector<bitset<2048>> dp(2);
  for (long long x = 0; x <= r; x++) dp[1][x] = true;
  for (long long x = 0; x < n; x++) {
    dp[x % 2] |= (dp[(x + 1) % 2] << a[x]);
    dp[x % 2] |= (dp[(x + 1) % 2] >> a[x]);
    for (long long y = r + 1; y < 2005; y++) dp[x % 2][y] = false;
    dp[((x + 1) % 2)].reset();
  }
  return dp[(n + 1) % 2].any();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long x = 0; x < n; x++) cin >> a[x];
    long long g = -1;
    for (long long x = 10; x >= 0; x--) {
      long long fi = g + (1 << x);
      if (!f(fi)) g = fi;
    }
    cout << g + 1 << "\n";
  }
}
