#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const long long mod = 998244353;
const long long N = 200200;
long long fact[N];
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
  long long small = 0, smaller = 0;
  for (long long i = 0; i < n; i++) {
    if (a[n - 1] - a[i] == 1)
      small++;
    else if (a[n - 1] - a[i] > 1)
      smaller++;
  }
  long long l = smaller;
  long long r = 0;
  ans -= fact[small + l];
  ans %= mod;
  if (ans < 0) ans += mod;
  while (l > 0) {
    r++;
    ans -= ((l * fact[small + l - 1]) % mod * fact[r]) % mod;
    ans %= mod;
    if (ans < 0) ans += mod;
    l--;
  }
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
