#include <bits/stdc++.h>
ll qpow(ll x, ll y = mod - 2) {
  ll t = 1;
  x %= mod;
  while (y) {
    if (y & 1) t = t * x M;
    y >>= 1;
    x = x * x M;
  }
  return t;
}
signed main() {
  int T;
  cin >> T;
  loop(kase, 1, T) {
    ll n, m, r, c, rr, cc, p;
    cin >> n >> m >> r >> c >> rr >> cc >> p;
    p = p * qpow(100) M;
    ll np = (mod + 1 - p) M;
    unordered_set<ll> vis;
    ll rd = 1, cd = 1;
    ll T, e = 0, cnt = 0;
    for (int i = 0;; i++) {
      if (r == n) rd = -1;
      if (r == 1) rd = +1;
      if (c == m) cd = -1;
      if (c == 1) cd = +1;
      {
        ll p = 0;
        p <<= 1;
        if (rd == 1) p |= 1;
        p <<= 1;
        if (cd == 1) p |= 1;
        p <<= 20;
        p |= r;
        p <<= 20;
        p |= c;
        if (vis.count(p)) {
          T = i;
          break;
        }
        vis.insert(p);
      }
      if (r == rr || c == cc) {
        e += qpow(np, cnt) * p M * i M;
        cnt++;
      }
      r += rd;
      c += cd;
    }
    e %= mod;
    np = qpow(np, cnt);
    p = (mod + 1 - np) M;
    ll ans = e * qpow(p) + T * np M * qpow(p);
    cout << ans M << '\n';
  }
}
