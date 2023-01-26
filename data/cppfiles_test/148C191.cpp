#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll hor[2][200005];
ll ver[2][200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll T;
  cin >> T;
  while (T--) {
    ll w, h;
    cin >> w >> h;
    ll h1, h2, v1, v2;
    cin >> h1;
    for (ll i = 0; i < h1; i++) {
      cin >> hor[0][i];
    }
    cin >> h2;
    for (ll i = 0; i < h2; i++) {
      cin >> hor[1][i];
    }
    cin >> v1;
    for (ll i = 0; i < v1; i++) {
      cin >> ver[0][i];
    }
    cin >> v2;
    for (ll i = 0; i < v2; i++) {
      cin >> ver[1][i];
    }
    ll vl1 = ver[0][v1 - 1] - ver[0][0];
    ll hh1 = max(hor[1][h2 - 1], hor[0][h1 - 1]);
    ll vl2 = ver[1][v2 - 1] - ver[1][0];
    ll hh2 = max(w - hor[0][0], w - hor[1][0]);
    ll hl1 = hor[0][h1 - 1] - hor[0][0];
    ll vh1 = max(ver[1][v2 - 1], ver[0][v1 - 1]);
    ll hl2 = hor[1][h2 - 1] - hor[1][0];
    ll vh2 = max(h - ver[0][0], h - ver[1][0]);
    ll ans = max({vl1 * w, vl2 * w, hl1 * h, hl2 * h});
    cout << ans << '\n';
  }
}
