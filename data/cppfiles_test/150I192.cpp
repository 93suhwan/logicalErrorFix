#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
long double pi = 3.141592653589793238462643383279;
const long long INF = 1e18 + 10;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long mod = 998244353;
long long power(long long x, long long y) {
  long long res = 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void bruteforce() {}
void init() {}
const long long mxN = 1e5 + 10;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long x = 0, y = 0, z = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] % 3 == 0) {
      x = max(x, a[i]);
    } else if (a[i] % 3 == 1) {
      y = max(y, a[i]);
    } else
      z = max(z, a[i]);
  }
  long long val1 = max({x / 3 - ((y && z) ? 1ll : 0ll), y / 3, z / 3}) +
                   (z ? 1ll : 0ll) + (y ? 1ll : 0ll);
  long long val2 = max({x / 3, y / 3, z / 3}) + 2;
  long long val3 = max({x / 3, (y / 3 - 1), z / 3}) + 2;
  cout << min({val1, val2, val3}) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long T = 1;
  cin >> T;
  for (long long i = 1; i <= T; i++) {
    solve();
  }
}
