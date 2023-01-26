#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (auto &x : h) {
      cin >> x;
    }
    auto ok = [&h, &n](int x) {
      vector<ll> f(h);
      for (int i = n - 1; i >= 2; --i) {
        if (f[i] < x) {
          return false;
        }
        ll d = min((f[i] - x) / 3, h[i] / 3);
        f[i] -= d * 3;
        assert(f[i] >= x);
        f[i - 1] += d;
        f[i - 2] += d * 2;
      }
      return f[0] >= x && f[1] >= x;
    };
    ll l = 1, r = 1e9 + 1;
    while (l + 1 < r) {
      ll m = (l + r) / 2;
      if (ok(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << l << '\n';
  }
  return 0;
}
