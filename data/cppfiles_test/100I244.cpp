#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int mxN = 2e5 + 5;
vector<ll> fact(mxN);
ll mul(ll a, ll b) { return (a * b) % MOD; }
ll add(ll a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
ll sub(ll a, ll b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
ll binpow(ll a, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}
ll inv(ll x) { return binpow(x, MOD - 2); }
ll C(ll k, ll n) { return mul(fact[n], inv(mul(fact[k], fact[n - k]))); }
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int mx = *max_element(a.begin(), a.end());
  int cnt = count(a.begin(), a.end(), mx - 1);
  if (a[n - 1] == mx) {
    cout << fact[n] << endl;
    return;
  }
  if (cnt == 0) {
    cout << 0 << endl;
    return;
  }
  ll ans = mul(mul(fact[cnt], fact[n - cnt - 1]) * C(cnt + 1, n), cnt);
  cout << ans << endl;
}
void cf() {
  int tt;
  cin >> tt;
  while (tt--) solve();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i <= mxN; i++) fact[i] = mul(fact[i - 1], i);
  cf();
  return 0;
}
