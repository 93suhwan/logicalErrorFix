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
  vector<vector<bool>> dp(2, vector<bool>(r + 1, false));
  dp[1].assign(r + 1, true);
  for (long long x = 0; x < n; x++) {
    for (long long y = 0; y <= r; y++) {
      if (y >= a[x]) {
        dp[x % 2][y] = (dp[x % 2][y] | dp[(x + 1) % 2][y - a[x]]);
      }
      if (y + a[x] <= r)
        dp[x % 2][y] = (dp[x % 2][y] | dp[(x + 1) % 2][y + a[x]]);
    }
    dp[((x + 1) % 2)].assign(r + 1, false);
  }
  for (long long x = 0; x < r; x++)
    if (dp[(n + 1) % 2][x]) return true;
  return false;
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
