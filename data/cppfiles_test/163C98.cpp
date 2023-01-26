#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int t;
ll n, m, a, b, c, d, p;
ll pp[500009];
ll qq[500009];
ll h[500009];
const ll mod = 1000000007;
ll gcd(ll x, ll y) {
  if (x == 1 | y == 1) return 1;
  return x % y ? gcd(y, x % y) : y;
}
ll fpow(ll b, ll p) {
  ll ans = 1, t = b;
  while (p) {
    if (p % 2) ans = (ans * t) % mod;
    t = (t * t) % mod;
    p /= 2;
  }
  return ans;
}
int main() {
  scanf("%d", &t);
  h[0] = 1;
  h[1] = fpow(100, mod - 2);
  for (int i = 2; i < 500000; ++i) {
    h[i] = (h[i - 1] * h[1]) % mod;
  }
  while (t--) {
    scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &a, &b, &c, &d, &p);
    pp[0] = 1;
    qq[0] = 1;
    pp[1] = p;
    qq[1] = 100 - p;
    for (int i = 2; i < 500000; ++i) {
      pp[i] = pp[i - 1] * p % mod;
      qq[i] = qq[i - 1] * (100 - p) % mod;
    }
    vector<ll> nrem;
    vector<ll> mrem;
    set<ll> setrem;
    nrem.push_back((c - a + 2 * n - 2) % (2 * n - 2));
    nrem.push_back(2 * n - c - a);
    mrem.push_back((d - b + 2 * m - 2) % (2 * m - 2));
    mrem.push_back(2 * m - d - b);
    ll g = gcd(n - 1, m - 1);
    ll cy = (n - 1) / g * (m - 1);
    for (ll i = 0; i < cy / (n - 1); ++i) {
      for (int j = 0; j < nrem.size(); ++j) {
        setrem.insert(nrem[j] + i * 2 * (n - 1));
      }
    }
    for (ll i = 0; i < cy / (m - 1); ++i) {
      for (int j = 0; j < mrem.size(); ++j) {
        setrem.insert(mrem[j] + i * 2 * (m - 1));
      }
    }
    vector<ll> rem;
    for (auto f : setrem) {
      if (f >= 0 && f < 2 * cy) {
        rem.push_back(f % mod);
      }
    }
    int remsi = rem.size();
    ll ans = 0;
    for (int i = 0; i < remsi; ++i) {
      if (i > 0) {
        ll t = (rem[i] * qq[i]) % mod;
        t = t * h[i + 1] % mod;
        ans = (ans + t) % mod;
      } else
        ans = (ans + rem[i] * h[i + 1]) % mod;
    }
    ans = (ans * pp[1]) % mod;
    ll fac = fpow(100, remsi) - fpow(100 - p, remsi);
    fac = ((fac % mod) + mod) % mod;
    fac = fpow(fac, mod - 2);
    fac = fac * fpow(100, remsi) % mod;
    ans = ans * fac % mod;
    ll ans2 = 2 * cy;
    ll ccc = fpow(100, remsi) - fpow(100 - p, remsi);
    ccc = ((ccc % mod) + mod) % mod;
    ccc = fpow(ccc, mod - 2);
    ccc = ccc * fpow(100 - p, remsi) % mod;
    ans2 = (ans2 * ccc) % mod;
    ans = (ans + ans2) % mod;
    printf("%lld\n", ans);
  }
}
