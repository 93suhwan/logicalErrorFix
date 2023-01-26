#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using str = string;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
const ld PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
mt19937 rnd(31313121);
str Y = "YES\n";
str N = "NO\n";
const ll INF = 2e18 + 10;
const ll Mod = 1e9 + 7;
const ll Maxn = 2e5 + 10;
vll gr[Maxn];
bool used[Maxn];
ll tim[Maxn];
void dfs(ll v, ll &vl) {
  used[v] = true;
  vl = min(vl, tim[v]);
  for (ll adj : gr[v]) {
    if (!used[adj]) dfs(adj, vl);
  }
}
void solve() {
  map<ll, vector<pll>> x;
  map<ll, vector<pll>> y;
  ll n, k;
  cin >> n >> k;
  for (ll i = 0; i < n; ++i) gr[i].clear();
  fill(used, used + n, false);
  for (ll i = 0; i < n; ++i) {
    ll xx, yy;
    ll t;
    cin >> xx >> yy;
    cin >> t;
    x[xx].push_back({yy, i});
    y[yy].push_back({xx, i});
    tim[i] = t;
  }
  for (auto [id, xs] : x) {
    sort(((xs).begin()), ((xs).end()));
    for (ll i = 0; i < (ll)xs.size() - 1; ++i) {
      if (xs[i + 1].first - xs[i].first <= k) {
        gr[xs[i + 1].second].push_back(xs[i].second);
        gr[xs[i].second].push_back(xs[i + 1].second);
      }
    }
  }
  for (auto [id, ys] : y) {
    sort(((ys).begin()), ((ys).end()));
    for (ll i = 0; i < (ll)ys.size() - 1; ++i) {
      if (ys[i + 1].first - ys[i].first <= k) {
        gr[ys[i + 1].second].push_back(ys[i].second);
        gr[ys[i].second].push_back(ys[i + 1].second);
      }
    }
  }
  vll es;
  for (ll i = 0; i < n; ++i) {
    if (!used[i]) {
      ll v = INF;
      dfs(i, v);
      es.push_back(v);
    }
  }
  sort(((es).begin()), ((es).end()));
  deque<ll> q;
  for (ll el : es) q.push_back(el);
  ll ans = 0;
  while ((ll)q.size()) {
    while ((ll)q.size() && q.front() == ans) q.pop_front();
    if ((ll)q.size()) {
      q.pop_back();
    }
    ++ans;
  }
  cout << ans - 1 << '\n';
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
