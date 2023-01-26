#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
ll mod = 1e9 + 7;
int const N = 3e5 + 100;
mt19937 rnd;
ll random(ll limit) {
  uniform_int_distribution<ll> uniform_dist(0, limit);
  return uniform_dist(rnd);
}
ll bpow(ll a, ll p) {
  ll res = 1;
  while (p > 0) {
    if (p % 2) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    p /= 2;
  }
  return res;
}
ll inv(ll a) { return bpow(a, mod - 2); }
void solve() {
  ll n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  ll x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll dx = min(abs(x1 - x2), c);
  ll dy = min(abs(y1 - y2), r);
  ll num1 = dx * r + dy * (c - dx);
  if (dx == 0 && dy == 0) {
    num1 = r * c;
  } else if (dx == 0) {
    num1 = c * dy;
  } else if (dy == 0)
    num1 = r * dx;
  ll x3 = max(x1, x2);
  ll x4 = min(x1 + c, x2 + c);
  ll y3 = max(y1, y2);
  ll y4 = min(y1 + r, y2 + r);
  ll num3 = (x4 - x3) * (y4 - y3);
  if (y4 <= y3 || x4 <= x3) num3 = 0;
  ll num2 = n * m - (2 * r * c - num3);
  ll num = num1 + num2;
  ll ans = bpow(k, num);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  rnd = mt19937(956231);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
