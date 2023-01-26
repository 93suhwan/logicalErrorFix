#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  ll a[n];
  map<ll, ll> m;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  for (auto it : m) {
    if (it.second > 1) {
      cout << "YES" << endl;
      return;
    }
  }
  ll c = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] != (i + 1)) c++;
  }
  if (c == 2 || c == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
