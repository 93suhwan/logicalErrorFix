#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll minf = 0xc0c0c0c0c0c0c0c0;
ll dp[512];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = -1;
  for (auto i : a) {
    vector<pi> v;
    for (ll j = 0; j < 512; j++) {
      if (dp[j] < i) {
        v.emplace_back(j ^ i, i);
      }
    }
    for (auto [j, k] : v) {
      dp[j] = min(dp[j], k);
    }
  }
  vector<ll> res;
  for (ll i = 0; i < 512; i++) {
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
