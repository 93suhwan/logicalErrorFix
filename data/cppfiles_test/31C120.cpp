#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  vector<array<ll, 2>> t;
  vector<ll> res(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
    t.push_back({v[i], i});
  }
  sort(t.begin(), t.end());
  while (!t.empty()) {
    ll m = t.size();
    if (m == 3) {
      array<ll, 2> a = t.back();
      t.pop_back();
      array<ll, 2> b = t.back();
      t.pop_back();
      array<ll, 2> c = t.back();
      t.pop_back();
      if (b[0] == c[0]) swap(a, c);
      if (a[0] == b[0]) {
        res[a[1]] = c[0];
        res[b[1]] = -2 * c[0];
        res[c[1]] = b[0];
      } else {
        res[a[1]] = b[0] - c[0];
        res[b[1]] = c[0] - a[0];
        res[c[1]] = a[0] - b[0];
      }
      break;
    }
    array<ll, 2> p1 = t.back();
    t.pop_back();
    array<ll, 2> p2 = t.back();
    t.pop_back();
    if (p1[0] == p2[0]) {
      res[p1[1]] = -1;
      res[p2[1]] = 1;
    } else {
      res[p1[1]] = -p2[0];
      res[p2[1]] = p1[0];
    }
  }
  for (auto x : res) cout << x << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _t = 1;
  cin >> _t;
  for (int i = 1; i <= _t; i++) {
    solve();
  }
  {};
  return 0;
}
