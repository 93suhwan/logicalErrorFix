#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return a % b ? gcd(b, a % b) : b; }
const long long mod = 998244353;
const long long inf = 1e18;
long long qpow(long long a, long long b) {
  long long t = 1;
  while (b != 0) {
    if (b & 1) t = (t * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return t;
}
template <typename T>
void re(T& a) {
  for (auto& t : a) cin >> t;
}
template <typename T>
void pr(T& a) {
  for (auto& t : a) cout << t << " ";
  cout << endl;
}
const int N = 5e5 + 5;
long long a[N];
long long dp[N];
long long pd[N];
int n;
void add(long long& x, long long y) { x = ((x + y) % mod + mod) % mod; }
void solve() {
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    dp[i] = 0;
    pd[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    long long x = a[i];
    long long tmp = dp[x];
    if (x == 0) {
      add(tmp, 1);
    } else {
      add(tmp, dp[x - 1]);
    }
    add(dp[x], tmp);
    if (x == 0) {
      continue;
    }
    tmp = pd[x];
    if (x == 1) {
      add(tmp, 1);
    } else {
      add(tmp, dp[x - 2]);
    }
    add(pd[x], tmp);
  }
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    add(ans, dp[i]);
    add(ans, pd[i]);
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
