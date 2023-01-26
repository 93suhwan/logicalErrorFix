#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const long long mod = 998244353;
const long long N = 200200;
long long fact[N];
long long pwr(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) {
      ans = (ans * x) % mod;
    }
    x = (x * x) % mod;
    y /= 2;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a[n - 1] == a[n - 2]) {
    cout << fact[n] << "\n";
    return;
  }
  if (a[n - 1] - a[n - 2] > 1) {
    cout << 0 << "\n";
    return;
  }
  long long ans = fact[n];
  long long small = 0;
  for (long long i = 0; i < n; i++) {
    if (a[n - 1] - a[i] == 1) small++;
  }
  ans -= (fact[n] * pwr(small + 1, mod - 2)) % mod;
  if (ans < 0) ans += mod;
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= mod;
  }
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
