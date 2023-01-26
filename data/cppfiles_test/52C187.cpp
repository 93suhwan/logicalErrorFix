#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void Solve() {
  ll n;
  cin >> n;
  ll s = 0;
  ll m = -1000000000;
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    s += x;
    m = max(x, m);
  }
  cout.precision(18);
  cout << fixed << double(m) + double(s - m) / (n - 1) << "\n";
}
int main() {
  ll t;
  cin >> t;
  for (ll i = 0; i < t; ++i) Solve();
  return 0;
}
