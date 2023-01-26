#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll w1 = x1, h1 = y1;
    ll w2 = n - x2;
    ll h2 = m - y2;
    ll w, h;
    cin >> w >> h;
    if ((abs(x1 - x2) + w) > n && (abs(y1 - y2) + h) > m) {
      cout << -1 << "\n";
    } else {
      ll hr = 0, wr = 0;
      if (w <= w1 || w <= w2) {
        wr = 0;
      } else {
        wr = w - max(w1, w2);
      }
      if (h <= h1 || h <= h2) {
        hr = 0;
      } else {
        hr = h - max(h1, h2);
      }
      if ((abs(x1 - x2) + w) > n) {
        cout << hr << "."
             << "000000"
             << "\n";
      } else if ((abs(y1 - y2) + h) > m) {
        cout << wr << "."
             << "000000"
             << "\n";
      } else {
        cout << min(hr, wr) << "."
             << "000000"
             << "\n";
      }
    }
  }
}
