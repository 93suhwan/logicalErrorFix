#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
const ll MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ll n, m, x, y;
  cin >> n;
  vector<ll> arr(n);
  ll total = 0;
  for (ll i = 0; i < (n); ++i) {
    cin >> arr[i];
    total += arr[i];
  }
  sort((arr).begin(), (arr).end());
  cin >> m;
  while (m--) {
    cin >> x >> y;
    ll a1 = 0, a2 = 0, d;
    auto itr = lower_bound(arr.begin(), arr.end(), x);
    if (itr == arr.end())
      a1 = arr[n - 1];
    else {
      a1 = *itr;
      if (n > 1) {
        itr--;
        a2 = *itr;
      }
    }
    d = total - a1;
    ll ans1 = max(x - a1, 0ll) + max(y - d, 0ll);
    d = total - a2;
    ll ans2 = max(x - a2, 0ll) + max(y - d, 0ll);
    ll ans = min(ans1, ans2);
    cout << ans << '\n';
  }
  return 0;
}
