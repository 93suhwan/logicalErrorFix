#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
template <typename T, typename U>
inline istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
inline istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}
const ll MOD = 1e9 + 7;
inline ll md(ll x, const ll& M = MOD) {
  x %= M;
  return ((x < 0) ? (x + M) : x);
}
ll pw(ll x, ll y, const ll& M = MOD) {
  if (y < 0) {
    x = pw(x, -y, M);
    return pw(x, M - 2, M);
  }
  ll res = 1;
  x = md(x, M);
  while (y > 0) {
    if (y & 1) {
      res = md(res * x, M);
    }
    x = md(x * x, M);
    y >>= 1;
  }
  return md(res, M);
}
void solve(ll& tc) {
  ll n, k;
  cin >> n >> k;
  ll ans = pw(md(pw(2, n - 1) + (n & 1)), k);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll rep = 1;
  while (rep--) {
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; i++) {
      if (0) cerr << "Case #" << i << "\n";
      solve(i);
    }
    if (1) break;
  }
  return 0;
}
