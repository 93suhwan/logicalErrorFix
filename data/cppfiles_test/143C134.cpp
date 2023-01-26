#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<ll> freq(n + 1);
    for (auto x : a) freq[x]++;
    set<ll> rem;
    vector<ll> extras;
    ll sum = 0;
    bool skip = false;
    for (ll i = 0; i <= n; i++) {
      if (skip) {
        cout << -1 << " ";
        continue;
      }
      ll ans = sum + freq[i];
      if (rem.size()) ans = -1;
      if (ans == -1) skip = true;
      cout << ans << " ";
      if (!freq[i]) {
        rem.insert(i);
      } else {
        while (freq[i] > 1) {
          extras.push_back(i);
          freq[i]--;
        }
      }
      while (rem.size() && extras.size()) {
        ll x = *rem.rbegin();
        rem.erase(x);
        ll y = extras.back();
        extras.pop_back();
        sum += x - y;
      }
    }
    cout << "\n";
  }
  return 0;
}
