#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &elt : a) cin >> elt;
  ;
  ll xx = a[n - 1], cnt = 0;
  ll maxx = *max_element(a.begin(), a.end());
  for (ll i = n - 1; i >= 0; i--) {
    if (xx == maxx) {
      cout << cnt << endl;
      return;
    }
    if (a[i] > xx) {
      xx = a[i];
      cnt++;
    }
  }
  cout << cnt << endl;
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
