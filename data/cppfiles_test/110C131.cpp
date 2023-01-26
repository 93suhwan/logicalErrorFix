#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n);
  for (ll i = 0; i < n; i++) {
    ll k;
    cin >> k;
    for (ll j = 0; j < k; j++) {
      ll x;
      cin >> x;
      x--;
      adj[x].push_back(i);
    }
  }
  vector<ll> vis(n, 0);
  bool isCycle = false;
  function<void(ll)> dfs = [&](ll v) {
    vis[v] = 1;
    for (auto x : adj[v]) {
      if (vis[x] == 1)
        isCycle = true;
      else if (!vis[x])
        dfs(x);
    }
    vis[v] = 2;
  };
  for (ll i = 0; i < n; i++) {
    if (!vis[i]) dfs(i);
  }
  if (isCycle) {
    cout << "-1"
         << "\n";
    return;
  }
  ll res = 0;
  vector<ll> dp(n, -1);
  function<ll(ll)> rec = [&](ll v) {
    if (dp[v] != -1) return dp[v];
    ll ans = 0;
    for (auto x : adj[v]) {
      if (x > v)
        ans = max(ans, rec(x));
      else
        ans = max(ans, rec(x) + 1);
    }
    return dp[v] = ans;
  };
  for (ll i = 0; i < n; i++) res = max(res, rec(i));
  cout << res + 1 << "\n";
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
