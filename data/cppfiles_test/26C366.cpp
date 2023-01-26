#include <bits/stdc++.h>
using namespace std;
const long long INF = -1e18;
const long long mod = 1e9 + 7;
long long binpow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = (r * b) % mod;
    b = (b * b) % mod;
    p /= 2;
  }
  return r;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long fact[200005] = {0};
  fact[0] = 1;
  for (long long i = 1; i < 200005; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = fact[2 * n];
    ans = (ans * binpow(2, mod - 2)) % mod;
    cout << ans << endl;
  }
  return 0;
}
