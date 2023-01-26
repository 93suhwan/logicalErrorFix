#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n);
  vector<ll> indegree(n, 0);
  for (ll i = 0; i < n; i++) {
    ll k;
    cin >> k;
    for (ll j = 0; j < k; j++) {
      ll x = i, y;
      cin >> y;
      y--;
      adj[y].push_back(x);
      indegree[x]++;
    }
  }
  vector<ll> topo;
  queue<ll> q;
  vector<ll> r(n, 1);
  for (ll i = 0; i < n; i++) {
    if (indegree[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    ll v = q.front();
    q.pop();
    topo.push_back(v);
    for (auto x : adj[v]) {
      indegree[x]--;
      if (indegree[x] == 0) q.push(x);
      if (v < x)
        r[x] = max(r[x], r[v]);
      else
        r[x] = max(r[x], r[v] + 1);
    }
  }
  if ((ll)topo.size() < n)
    cout << -1 << "\n";
  else
    cout << *max_element(r.begin(), r.end()) << "\n";
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
