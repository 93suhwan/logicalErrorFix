#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve() {
  ll n, ans = 0;
  cin >> n;
  ll a[n];
  for (auto &elt : a) cin >> elt;
  ;
  for (int l = 0; l < n - 1; l++) {
    ll maxx = max(a[l], a[l + 1]), minn = min(a[l], a[l + 1]);
    ans = max(ans, maxx * minn);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
