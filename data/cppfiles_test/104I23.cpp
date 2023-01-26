#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    ll a[n], b[n];
    ll diff = 0;
    for (int i = 0; i < (int)n; i++) {
      cin >> a[i] >> b[i];
      diff += a[i] - b[i];
    }
    vector<ll> aa(n), bb(n), r(n);
    for (int i = 0; i < (int)n; i++) {
      aa[i] += max(0LL, m - b[i]);
      bb[i] += max(0LL, m - a[i]);
      r[i] = m - aa[i] - bb[i];
      diff -= aa[i] - bb[i];
    }
    for (int i = 0; i < (int)n; i++) {
      if (diff >= 0) {
        aa[i] += min(diff, r[i]);
        ll res = r[i] - min(diff, r[i]);
        diff -= min(diff, r[i]);
        aa[i] += (res + 1) / 2;
        bb[i] += res / 2;
        if (res % 2) diff++;
      } else {
        bb[i] += min(-diff, r[i]);
        ll res = r[i] - min(-diff, r[i]);
        diff += min(-diff, r[i]);
        aa[i] += (res + 1) / 2;
        bb[i] += res / 2;
        if (res % 2) diff--;
      }
    }
    cout << abs(diff) << endl;
    for (int i = 0; i < (int)n; i++) cout << aa[i] << " " << bb[i] << endl;
  }
  return 0;
}
