#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const ll inf = 9223372036854775807;
struct segment_tree {
  vector<ll> t;
  ll combine(ll a, ll b) { return a + b; }
  void build(vector<ll> a, ll v, ll tl, ll tr) {
    if (tl == tr && tl < a.size())
      t[v] = a[tl];
    else if (tl >= a.size())
      return;
    else {
      ll tm = (tl + tr) / 2;
      build(a, v * 2, tl, tm);
      build(a, v * 2 + 1, tm + 1, tr);
      t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
  }
  ll get_sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r || tl > tr) return 0;
    if (l == tl && r == tr) {
      return t[v];
    }
    ll tm = (tl + tr) / 2;
    return combine(get_sum(v * 2, tl, tm, l, min(r, tm)),
                   get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr)
      t[v] = new_val;
    else {
      ll tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
      else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
};
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll> > a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  vector<pair<ll, ll> > b = a;
  ll cur = 0, mx = 0, mn = inf;
  for (ll i = 0; i < n; i++) {
    if (i > 0 && a[i].first == a[i - 1].first)
      b[i].first = b[i - 1].first;
    else {
      b[i].first = cur;
      cur++;
    }
    mx = max(mx, b[i].first);
    mn = min(mn, b[i].first);
  }
  sort(b.begin(), b.end(),
       [](pair<ll, ll> x, pair<ll, ll> y) { return x.second < y.second; });
  a = b;
  segment_tree tr;
  tr.t.resize((1 << 19));
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll ls = tr.get_sum(1, 0, (1 << 18) - 1, 0, a[i].first - 1),
       mr = tr.get_sum(1, 0, (1 << 18) - 1, a[i].first + 1, (1 << 18) - 1);
    if (ls <= mr)
      ans += ls;
    else if (ls >= mr)
      ans += mr;
    tr.update(1, 0, (1 << 18) - 1, a[i].first,
              tr.t[(1 << 18) + a[i].first] + 1);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << setprecision(6) << fixed;
  ll tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
