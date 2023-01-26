#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3", "unroll-loops")
long long mod = 1e9 + 7;
void solve();
void tests() {
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
}
long long power(long long x, unsigned long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void io_files() {}
int32_t main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  ;
  cout << fixed << setprecision(20);
  ;
  if (1) io_files();
  if (1)
    tests();
  else
    solve();
}
void solve() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  for (long long i = 0; i < 32; i++) {
    if ((1 << i) & k) ans += power(n, i, mod);
    ans %= mod;
  }
  cout << ans << endl;
}
