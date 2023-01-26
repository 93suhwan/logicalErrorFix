#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll minf = 0xc0c0c0c0c0c0c0c0;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<vector<ll>> v(5050);
  vector<ll> dp(10010, inf);
  for (ll i = 1; i <= n; i++) {
    ll a;
    cin >> a;
    v[a].push_back(i);
  }
  dp[0] = -1;
  for (ll i = 0; i <= 5000; i++) {
    for (ll j = 0; j <= 8192; j++) {
      auto it = upper_bound((v[i]).begin(), (v[i]).end(), dp[j]);
      if (it != v[i].end()) {
        dp[i ^ j] = min(dp[i ^ j], *it);
      }
    }
  }
  vector<ll> res;
  for (ll i = 0; i <= 8192; i++) {
    if (dp[i] != inf) {
      res.push_back(i);
    }
  }
  cout << ll((res).size()) << '\n';
  for (auto i : res) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}
