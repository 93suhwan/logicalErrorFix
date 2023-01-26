#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = (1e9) + 7;
ll bexpo(ll a, ll b, ll mod) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b = b >> 1;
  }
  return ans;
}
void solve() {
  ll n, m, a, b, c, d, p;
  cin >> n >> m >> a >> b >> c >> d >> p;
  ll sz = 0, sz2, dr = 1, dc = 1;
  if (a == n and dr == 1) dr = -1;
  if (a == 1 and dr == -1) dr = 1;
  if (b == m and dc == 1) dc = -1;
  if (b == 1 and dc == -1) dc = 1;
  vector<ll> times;
  set<vector<ll>> check;
  while (1) {
    vector<ll> temp = {a, b, dr, dc};
    if (check.find(temp) == check.end())
      check.insert(temp);
    else
      break;
    if (a == c or b == d) {
      times.push_back(sz);
    }
    a += dr;
    b += dc;
    if (a == n and dr == 1) dr = -1;
    if (a == 1 and dr == -1) dr = 1;
    if (b == m and dc == 1) dc = -1;
    if (b == 1 and dc == -1) dc = 1;
    sz += 1;
  }
  sz2 = times.size();
  ll t1 = bexpo(100, mod - 2, mod);
  ll t2 = (p * t1) % mod;
  vector<ll> invp(sz2 + 1);
  invp[0] = 1;
  for (int i = 1; i <= sz2; i++) {
    invp[i] = (invp[i - 1] * (100LL - p)) % mod;
    invp[i] = (invp[i] * t1) % mod;
  }
  ll t3 = 1 - invp[sz2];
  t3 = (t3 + mod) % mod;
  t3 = bexpo(t3, mod - 2, mod);
  ll ans = 0;
  for (int i = 0; i < sz2; i++) {
    ll temp = (invp[i] * t2) % mod;
    ll temp2 = (temp * times[i]) % mod;
    ll temp3 = (temp * invp[sz2]) % mod;
    temp3 = (temp3 * sz) % mod;
    temp3 = (temp3 * t3) % mod;
    ll temp4 = (temp2 + temp3) % mod;
    temp4 = (temp4 * t3) % mod;
    ans = (ans + temp4) % mod;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
