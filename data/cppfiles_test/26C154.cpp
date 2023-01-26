#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long powmod(long long a, long long b) {
  long long res = 1;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  long long ans = n;
  for (int i = 2; i < 2 * n; ++i) ans = (ans * 1ll * i) % mod;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, Tc = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
