#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
struct edge {
  ll to;
  ll cost;
};
using graph = vector<vector<edge>>;
const ll INF = 1e18;
inline void chmax(ll& a, ll b) { a = max(a, b); }
inline void chmin(ll& a, ll b) { a = min(a, b); }
long double pi = acos(-1);
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll dx[4]{1, 0, -1, 0};
ll dy[4]{0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  ll m = n * k;
  vector<ll> A(m);
  for (ll i = 0; i < (m); ++i) cin >> A[i];
  vector<vector<ll>> B(n);
  for (ll i = 0; i < (m); ++i) B[A[i] - 1].push_back(i);
  vector<vector<P>> unti(n);
  for (ll i = 0; i < (n); ++i)
    for (ll j = 0; j < (k - 1); ++j) {
      ll x = B[i][j];
      ll y = B[i][j + 1];
      unti.push_back({make_pair(x, y)});
    }
  vector<ll> seen(n);
  vector<P> ans(n);
  ll cnt = 0;
  bool ok = 0;
  for (ll i = 0; i < (n); ++i) {
    ll now = -1;
    while (1) {
      ll ma = INF;
      ll next = -1;
      ll soeji = -1;
      for (ll j = 0; j < (n); ++j) {
        if (seen[j]) continue;
        ll y = upper_bound(B[j].begin(), B[j].end(), now) - B[j].begin();
        if (y == k - 1 || y == k) continue;
        ll x = B[j][y + 1];
        if (x < ma) {
          ma = x;
          next = j;
          soeji = y;
        }
      }
      if (ma == INF) break;
      seen[next] = true;
      ans[next].first = B[next][soeji];
      ans[next].second = B[next][soeji + 1];
      now = ma;
      cnt++;
      if (cnt == n) {
        ok = 1;
        break;
      }
    }
    if (ok) break;
  }
  for (ll i = 0; i < (n); ++i)
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  return 0;
}
