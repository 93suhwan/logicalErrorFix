#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool comp(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.second != b.second) return a.second < b.second;
  return a.first < b.first;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n), b(n), m(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i] >> m[i];
    }
    map<ll, vector<ll>> all;
    for (int i = 0; i < n; ++i) {
      all[a[i] + b[i] - m[i]].push_back(i);
    }
    vector<ll> ans(n);
    for (const auto& p : all) {
      vector<ll> id = p.second;
      int col = id.size();
      vector<ll> L(col), R(col);
      for (int i = 0; i < col; ++i) {
        L[i] = a[id[i]] - min(a[id[i]], m[id[i]]);
        R[i] = a[id[i]] - max(0ll, m[id[i]] - b[id[i]]);
      }
      vector<pair<ll, ll>> kek(col);
      for (int i = 0; i < col; ++i) {
        kek[i] = {L[i], R[i]};
      }
      sort(kek.begin(), kek.end(), comp);
      vector<ll> now;
      ll past = -1;
      for (int i = 0; i < col; ++i) {
        if (past < kek[i].first) {
          past = kek[i].second;
          now.push_back(past);
        }
      }
      sum += now.size();
      for (int i = 0; i < col; ++i) {
        ll c = *upper_bound(now.begin(), now.end(), L[i] - 1);
        ans[id[i]] = a[id[i]] - c;
      }
    }
    cout << sum << '\n';
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << ' ' << m[i] - ans[i] << '\n';
    }
  }
  return 0;
}
