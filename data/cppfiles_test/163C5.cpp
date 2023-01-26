#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int tt;
int n, m, rb, cb, rd, cd, p;
ll bigmod(ll a, ll b) {
  if (b == 0) return 1;
  ll x = bigmod(a * a % mod, b >> 1);
  return b & 1 ? x * a % mod : x;
}
ll inv(ll a) {
  a %= mod;
  if (a < 0) a += mod;
  return bigmod(a, mod - 2);
}
void norm(int &a, int &b, int &c, int &d) {
  int nwa = a + c;
  int nwb = b + d;
  if (nwa == 0) nwa = 2, c *= -1;
  if (nwa == n + 1) nwa = n - 1, c *= -1;
  if (nwb == 0) nwb = 2, d *= -1;
  if (nwb == m + 1) nwb = m - 1, d *= -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    p = 1ll * p * bigmod(100, mod - 2) % mod;
    ll ter = 1 - p;
    if (ter < 0) ter += mod;
    map<vector<int>, bool> mp;
    int tp1 = 1, tp2 = 1;
    vector<int> v;
    int cnt = 0;
    while (1) {
      norm(rb, cb, tp1, tp2);
      if (mp.find({rb, cb, tp1, tp2}) != mp.end()) break;
      mp[{rb, cb, tp1, tp2}] = 1;
      if (rb == rd or cb == cd) v.push_back(cnt);
      cnt++;
      rb += tp1;
      cb += tp2;
    }
    int sz = (int)v.size();
    ll ans = 0;
    for (int i = 0; i < sz; i++) {
      ll a = v[i];
      ll G = 1ll * p * bigmod(ter, i) % mod;
      ll d = cnt;
      ll r = bigmod(ter, sz);
      ll jg = 1ll * a * inv(1 - r) % mod;
      ll jog = 1ll * d * r % mod;
      jog = jog * bigmod(inv(1 - r), 2) % mod;
      jg += jog;
      if (jg >= mod) jg -= mod;
      jg = jg * G % mod;
      ans += jg;
      if (ans >= mod) ans -= mod;
    }
    cout << ans << '\n';
  }
}
