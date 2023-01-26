#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1000000007;
const ll M1 = 998244353;
using vl = vector<ll>;
using pll = pair<ll, ll>;
ll powermod(ll x, ll y, ll mod) {
  if (y == 0) return 1;
  ll res = powermod(x, y / 2, mod);
  res = (res * res) % mod;
  if (y & 1) res = (res * x) % mod;
  return res;
}
ll power(ll x, ll y) {
  if (y == 0) return 1;
  ll res = power(x, y / 2);
  res = (res * res);
  if (y & 1) res = (res * x);
  return res;
}
void solve() {
  ll x, y;
  cin >> x >> y;
  if (y < x)
    cout << x * y + y << endl;
  else if (y % x == 0)
    cout << x << endl;
  else {
    ll m = (y % x) / 2;
    cout << x * y + m << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; i++) {
    solve();
  }
  return 0;
}
