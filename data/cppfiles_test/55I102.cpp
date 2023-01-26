#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long N = 2e5 + 1, mod = 1e9 + 7;
long long Power(long long a, long long b) {
  long long result = 1;
  a %= mod;
  while (b) {
    if (b % 2 == 1) result *= a;
    a *= a;
    a %= mod;
    result %= mod;
    b /= 2;
  }
  return result;
}
void solve() {
  long long n;
  cin >> n;
  cout << (6 * Power(4, Power(2, n) - 2)) % mod << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
