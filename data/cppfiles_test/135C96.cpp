#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = 0;
    for (ll i = 0; i < n - 2 * k; ++i) {
      res += a[i];
    }
    for (ll i = 0; i < k; ++i) {
      res += a[n - 2 * k + i] / a[n - k + i];
    }
    cout << res << endl;
  }
  return 0;
}
