#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using str = string;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
const ld PI = acos(-1);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ld INF = 1e12;
const ll Maxn = 10000;
str Y = "Yes\n";
str N = "No\n";
bool cmp(ll a, ll b) { return abs(a) < abs(b); }
void solve() {
  ll n, k;
  cin >> n >> k;
  vll pl;
  vll mn;
  ll mx = 0;
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (abs(x) > mx) mx = abs(x);
    if (x < 0)
      mn.push_back(x);
    else
      pl.push_back(x);
  }
  sort(((pl).begin()), ((pl).end()), cmp);
  sort(((mn).begin()), ((mn).end()), cmp);
  ll ans = 0;
  for (ll i = (ll)pl.size() - 1; i >= 0; i -= k) {
    ans += abs(pl[i]);
  }
  for (ll i = (ll)mn.size() - 1; i >= 0; i -= k) {
    ans += abs(mn[i]);
  }
  cout << 2 * ans - mx << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  for (ll i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
