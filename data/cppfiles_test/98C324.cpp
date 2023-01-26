#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll min(ll x, ll y) { return ((x < y) ? x : y); }
ll max(ll x, ll y) { return ((x > y) ? x : y); }
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> a, b;
  a.resize(n);
  b.resize(n);
  for (ll i = 0; n > i; i++) {
    a[i] = (s[i] == 'a');
    b[i] = (s[i] == 'b');
    if (i > 0) {
      a[i] += a[i - 1];
      b[i] += b[i - 1];
    }
  }
  for (ll i = 0; n > i; i++) {
    ll l = 0;
    if (i > 0) {
      l = b[i - 1] - a[i - 1];
    }
    for (ll j = i; n > j; j++) {
      ll r = b[j] - a[j];
      if (l == r) {
        cout << i + 1 << ' ' << j + 1 << '\n';
        return;
      }
    }
  }
  cout << "-1 -1\n";
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
