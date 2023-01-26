#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll binpow(ll x, ll n) {
  ll ans = 1;
  while (n != 0) {
    if (n & 1) ans = ans * x % 1000000007;
    ;
    x = x * x % 1000000007;
    ;
    n = n >> 1;
  }
  return ans;
}
ll isprime(ll x) {
  if (x < 2) {
    return 0;
  }
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
void solve() {
  ll n;
  cin >> n;
  string a[n], s = "";
  for (int i = 0; i < n - 2; i++) {
    cin >> a[i];
  }
  s += a[0][0];
  bool ok = 1;
  for (int i = 1; i < n - 2; i++) {
    if (a[i - 1][1] == a[i][0]) {
      s += a[i][0];
    } else {
      s += a[i - 1][1];
      s += a[i][0];
      ok = 0;
    }
  }
  s += a[n - 3][1];
  if (ok) {
    s += a[n - 3][1];
  }
  cout << s;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
