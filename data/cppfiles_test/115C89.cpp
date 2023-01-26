#include <bits/stdc++.h>
using ll = long long int;
using namespace std;
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, h;
    cin >> n >> h;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) cin >> vec[i];
    ll l = 1, r = pow(10, 18);
    ll ans;
    while (l <= r) {
      ll mid = (l + r) / 2, res = 0;
      for (int i = 0; i < n; i++) {
        if (i == n - 1)
          res += mid;
        else {
          ll x = vec[i + 1] - vec[i];
          if (x < mid)
            res += x;
          else
            res += mid;
        }
      }
      if (res >= h) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << ans << "\n";
  }
}
