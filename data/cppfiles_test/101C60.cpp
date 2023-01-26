#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
ll mod = 998244353LL;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin >> T;
  for (ll ic = 1; ic <= T; ic++) {
    ll n, m, k;
    cin >> n >> m >> k;
    map<ll, ll> hori, verti;
    vector<ll> x(n), y(m);
    vector<pair<ll, pair<ll, ll>>> xxx, yyy;
    for (ll i = 0; i < n; i++) {
      cin >> x[i];
      verti[x[i]] = 1;
      xxx.push_back({x[i], {1, 0}});
    }
    for (ll i = 0; i < m; i++) {
      cin >> y[i];
      hori[y[i]] = 1;
      yyy.push_back({y[i], {1, 0}});
    }
    ll hy = 0, vy = 0, hv = 0;
    for (ll i = 0; i < k; i++) {
      ll x1, y1;
      cin >> x1 >> y1;
      if (verti[x1] && hori[y1]) {
        hv++;
      } else if (verti[x1]) {
        vy++;
        yyy.push_back({y1, {0, x1}});
      } else {
        hy++;
        xxx.push_back({x1, {0, y1}});
      }
    }
    ll tot = 0;
    sort(xxx.begin(), xxx.end());
    sort(yyy.begin(), yyy.end());
    for (ll i = 0; i < xxx.size();) {
      while (i < xxx.size() && xxx[i].second.first == 1) {
        i++;
      }
      if (i == xxx.size()) break;
      map<ll, ll> mp;
      ll eee = 0;
      while (i < xxx.size() && xxx[i].second.first == 0) {
        mp[xxx[i].second.second]++;
        i++;
        eee++;
      }
      tot += ((eee * (eee - 1)) / 2);
      for (auto aa : mp) tot -= ((aa.second * (aa.second - 1)) / 2);
    }
    for (ll i = 0; i < yyy.size();) {
      while (i < yyy.size() && yyy[i].second.first == 1) {
        i++;
      }
      if (i == yyy.size()) break;
      map<ll, ll> mp;
      ll eee = 0;
      while (i < yyy.size() && yyy[i].second.first == 0) {
        mp[yyy[i].second.second]++;
        i++;
        eee++;
      }
      tot += ((eee * (eee - 1)) / 2);
      for (auto aa : mp) tot -= ((aa.second * (aa.second - 1)) / 2);
    }
    cout << tot << "\n";
  }
}
