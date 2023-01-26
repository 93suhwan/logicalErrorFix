#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long m2 = 1e9 + 7;
const long long INF64 = long long(1e18);
const long long max2 = 1e3 + 10;
const long long N = 1000001;
const long long MAXN = 2e5 + 10;
const long long MOD = 1e9 + 7;
const long long MaxN = 1040;
const long long ALPHABET_SIZE = 2;
long long m = 1000000007;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
vector<long long> v, p;
long long pos(long long k) {
  long long i, j;
  long long n = v.size();
  long long dp[n][k + 1];
  for (i = 0; i < n; ++i)
    for (j = 0; j <= k; ++j) dp[i][j] = LLONG_MIN;
  for (i = n - 1; i >= 0; --i) {
    for (j = 1; j <= k; ++j) {
      if (j == 1) {
        dp[i][j] = max((i + 1 < n ? dp[i + 1][j] : 0), v[i]);
        continue;
      }
      long long x = p[i + j - 1] - (i - 1 >= 0 ? p[i - 1] : 0);
      long long val = (i + j < n ? dp[i + j][j - 1] : LLONG_MIN);
      if (x < val) {
        dp[i][j] = max(dp[i + 1][j], val + x);
      }
    }
  }
  return (dp[0][k] != LLONG_MIN);
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long i, j;
    v.clear();
    p.clear();
    for (i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    long long s = 0;
    for (i = 0; i < n; ++i) {
      s += v[i];
      p.push_back(s);
    }
    long long x = sqrt(1 + 8 * n) / 2 + 5;
    long long l = 1, r = x;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if (pos(m)) {
        l = m;
      } else
        r = m - 1;
    }
    if (pos(r))
      cout << r << "\n";
    else
      cout << l << "\n";
  }
  return (0);
}
