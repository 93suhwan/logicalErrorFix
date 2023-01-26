#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    ll mx = 0;
    ll len = 0;
    ll first;
    while (n) {
      ll num = n % 10;
      mx = max(mx, num);
      len++;
      first = n % 10;
      n /= 10;
    }
    if (mx == first) {
      for (ll i = 1; i <= len; ++i) cout << first;
      cout << '\n';
    } else {
      for (ll i = 1; i <= len; ++i) cout << first + 1;
      cout << '\n';
    }
    return;
  } else {
    ll idx[20];
    ll cnt[20] = {0};
    ll all = 0;
    ll sav = n;
    ll pos = 0;
    while (n) {
      idx[++pos] = n % 10;
      if (cnt[n % 10] == 0) all++;
      cnt[n % 10]++;
      n /= 10;
    }
    if (all <= 2)
      cout << sav << '\n';
    else {
      sav = pos;
      ll first = idx[pos];
      while (idx[pos] == first) pos--;
      for (ll i = sav; i > pos; --i) cout << first;
      cout << idx[pos] + 1;
      for (ll i = pos - 1; i >= 1; --i) cout << min(idx[pos] + 1, first);
      cout << '\n';
    }
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll t;
  cin >> t;
  while (t--) solve();
}
