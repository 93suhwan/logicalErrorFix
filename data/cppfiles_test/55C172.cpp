#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
const long long MOD = 1e9 + 7;
const long long MAXN = 1e5 + 7;
const long long INF = 2e9;
const long long BIG_INF = 2e18;
const long long LOG = 20;
const double eps = 1e-7;
mt19937 engine(chrono::system_clock::now().time_since_epoch().count());
long long mpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return res;
}
void solve() {
  long long k;
  cin >> k;
  long long ans = 6, kol = 1;
  for (long long i = 0; i < k; ++i) {
    kol = kol * 2;
  }
  kol -= 2;
  cout << (ans * mpow(4, kol)) % MOD << '\n';
  ;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
