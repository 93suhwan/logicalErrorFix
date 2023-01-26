#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
const ll MOD = 1e9 + 7;
void solve() {
  ll n;
  cin >> n;
  ll arr[n];
  for (ll i = 0; i < (n); ++i) cin >> arr[i];
  ;
  ll ans = 0;
  for (ll i = 0; i < (n); ++i) {
    if (arr[i] > (i + 1 + ans)) ans += (arr[i] - (i + 1 + ans));
  }
  cout << ans << '\n';
  ;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ll n, m;
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
