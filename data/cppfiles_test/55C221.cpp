#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long inf = 1e15;
const long long mod = 1e9 + 7;
const long long N = 3e5 + 100;
long long ppow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}
void solve() {
  long long n;
  cin >> n;
  cout << 6 * ppow(4, (1ll << n) - 2) % mod;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  while (tt--) {
    solve();
    cout << '\n';
  }
}
