#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  ll ans = max(0ll, sum - k);
  for (ll i = n - 1; i > 0; i--) {
    sum -= a[i] - a[0];
    ll steps = n - i + (max(0ll, sum - k) + (n - i)) / (n - i + 1);
    ans = min(ans, steps);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
