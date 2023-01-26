#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using sl = set<ll>;
const ll MAXN = 1e5;
vl adj[MAXN];
bool vis[MAXN];
void dfs(ll cur) {
  if (vis[cur]) {
    return;
  }
  vis[cur] = true;
  for (ll x : adj[cur]) {
    dfs(x);
  }
}
void solve() {
  ll n;
  cin >> n;
  vpl a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first, a[i].second = i;
    adj[i].clear();
    vis[i] = false;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i].first, b[i].second = i;
  }
  sort(begin(a), end(a)), sort(begin(b), end(b));
  for (int i = 0; i < n - 1; i++) {
    adj[a[i].second].push_back(a[i + 1].second);
    adj[b[i].second].push_back(b[i + 1].second);
  }
  dfs(a[n - 1].second);
  dfs(b[n - 1].second);
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << endl;
}
int main() {
  ll t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
