#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll power(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b % 2 == 1) {
      ans = (ans * a);
    }
    a = (a * a);
    b /= 2;
  }
  return ans;
}
ll solve(ll g) {
  ll n;
  cin >> n;
  vll v(n, 0);
  for (ll i = 0; i < n; i++) cin >> v[i];
  ll cnt0 = 1 - v[0], cnt1 = v[0];
  ll ans = 1 + v[0];
  for (ll i = 1; i < n; i++) {
    if (v[i] == 0) {
      cnt0++;
      cnt1 = 0;
      if (cnt0 > 1) {
        cout << -1 << '\n';
        return 0;
      }
    } else {
      if (cnt1 >= 1) {
        ans += 5;
      } else {
        ans += 1;
      }
      cnt1++;
    }
  }
  cout << ans << '\n';
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll x = 1;
  ll t;
  cin >> t;
  while (t--) {
    ll z = solve(x);
  }
}
