#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];
  vector<ll> b = a;
  sort(b.begin(), b.end());
  for (ll i = 0; i < n; i++) {
    if (a == b) {
      cout << i << endl;
      return;
    }
    if (i % 2 == 0) {
      ll j = 0;
      ll t = n / 2;
      while (t--) {
        if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        j = j + 2;
      }
    }
    if (i % 2 == 1) {
      ll j = 1;
      ll t = n / 2;
      while (t--) {
        if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        j = j + 2;
      }
    }
  }
  cout << n << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
