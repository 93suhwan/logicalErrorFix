#include <bits/stdc++.h>
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> arr(n);
  multiset<ll> s;
  for (ll i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    s.insert(arr[i].first);
    s.insert(arr[i].second);
  }
  map<pair<ll, ll>, ll> M;
  queue<pair<ll, ll>> q;
  q.push({1, n});
  while (q.size()) {
    pair<ll, ll> temp = q.front();
    q.pop();
    if (s.find(temp.first) != s.end()) s.erase(s.find(temp.first));
    if (s.find(temp.second) != s.end()) s.erase(s.find(temp.second));
    if (temp.first == temp.second) {
      M[temp] = temp.first;
    } else {
      ll res = temp.first;
      for (ll i = temp.first; i <= temp.second; i++) {
        if (s.find(i) == s.end()) {
          res = i;
          break;
        }
      }
      M[temp] = res;
      if (res == temp.first) {
        q.push({temp.first + 1, temp.second});
      } else if (res == temp.second) {
        q.push({temp.first, temp.second - 1});
      } else {
        q.push({temp.first, res - 1});
        q.push({res + 1, temp.second});
      }
    }
  }
  for (auto x : M) {
    cout << x.first.first << " " << x.first.second << " " << x.second << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
