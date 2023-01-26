#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll w, h, x0, x1, y0, y1, max[4];
    cin >> w >> h;
    ll x[2][200001], y[2][200001];
    cin >> x0;
    for (int i = 0; i < x0; ++i) cin >> x[0][i];
    max[0] = x[0][x0 - 1] - x[0][0];
    cin >> x1;
    for (int i = 0; i < x1; ++i) cin >> x[1][i];
    max[1] = x[1][x1 - 1] - x[1][0];
    cin >> y0;
    for (int i = 0; i < y0; ++i) cin >> y[0][i];
    max[2] = y[0][y0 - 1] - y[0][0];
    cin >> y1;
    for (int i = 0; i < y1; ++i) cin >> y[1][i];
    max[3] = y[1][y1 - 1] - y[1][0];
    ll check[4] = {max[0] * h, max[1] * h, max[2] * w, max[3] * w};
    cout << *max_element(check, check + 4) << '\n';
  }
  return 0;
}
