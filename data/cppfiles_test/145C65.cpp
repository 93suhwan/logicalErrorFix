#include <bits/stdc++.h>
using namespace std;
const long long int M = 2e5 + 1;
vector<vector<long long int>> g(M), cc;
vector<long long int> vis(M), ind(M), cur, tim(M);
long long int n;
void dfs(long long int u) {
  vis[u] = true;
  cur.push_back(u);
  for (auto x : g[u]) {
    if (vis[x]) continue;
    dfs(x);
  }
}
bool pos(long long int k) {
  vector<long long int> v((long long int)cc.size(), 0);
  for (long long int i = 0; i < n; i++) {
    if (tim[i] <= k) {
      v[ind[i]] = 1;
    }
  }
  long long int req = 0;
  for (auto x : v) {
    if (!x) req++;
  }
  return (req <= (k + 1));
}
void solve() {
  long long int k;
  cin >> n >> k;
  vector<pair<long long int, long long int>> v(n);
  map<long long int, vector<pair<long long int, long long int>>> mpx, mpy;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    mpx[v[i].first].push_back(make_pair(v[i].second, i));
    mpy[v[i].second].push_back(make_pair(v[i].first, i));
    cin >> tim[i];
  }
  for (auto X : mpx) {
    auto x = X.second;
    sort(x.begin(), x.end());
    for (long long int i = 1; i < (long long int)x.size(); i++) {
      if (x[i].first - x[i - 1].first <= k) {
        g[x[i].second].push_back(x[i - 1].second);
        g[x[i - 1].second].push_back(x[i].second);
      }
    }
  }
  for (auto X : mpy) {
    auto x = X.second;
    sort(x.begin(), x.end());
    for (long long int i = 1; i < (long long int)x.size(); i++) {
      if (x[i].first - x[i - 1].first <= k) {
        g[x[i].second].push_back(x[i - 1].second);
        g[x[i - 1].second].push_back(x[i].second);
      }
    }
  }
  for (long long int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
      for (auto x : cur) {
        ind[x] = (long long int)cc.size();
      }
      cc.push_back(cur);
      cur.clear();
    }
  }
  long long int l = 0, r = n + 1;
  while (l <= r) {
    long long int mid = (l + r) / 2;
    if (pos(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l << '\n';
  for (long long int i = 0; i < n; i++) {
    g[i].clear();
    vis[i] = false;
  }
  cc.clear();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
