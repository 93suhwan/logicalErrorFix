#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10;
int n, k, T[MAXN], cmpid;
map<int, vector<pair<int, int>>> C, R;
vector<int> cmp[MAXN], adj[MAXN];
bool vis[MAXN];
void dfs(int v) {
  cmp[cmpid].push_back(v);
  vis[v] = true;
  for (int u : adj[v])
    if (!vis[u]) dfs(u);
}
inline void solve() {
  R.clear();
  C.clear();
  cmpid = 0;
  for (int i = 0; i < n + 5; i++) {
    adj[i].clear();
    cmp[i].clear();
    T[i] = 0;
    vis[i] = false;
  }
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    T[i] = t;
    R[x].push_back({y, i});
    C[y].push_back({x, i});
  }
  for (auto f : R) {
    vector<pair<int, int>> vec = f.second;
    sort((vec).begin(), (vec).end());
    for (int i = 0; i < int(vec.size()) - 1; i++) {
      if (vec[i].first >= vec[i + 1].first - k) {
        adj[vec[i].second].push_back(vec[i + 1].second);
        adj[vec[i + 1].second].push_back(vec[i].second);
      }
    }
  }
  for (auto f : C) {
    vector<pair<int, int>> vec = f.second;
    sort((vec).begin(), (vec).end());
    for (int i = 0; i < int(vec.size()) - 1; i++) {
      if (vec[i].first >= vec[i + 1].first - k) {
        adj[vec[i].second].push_back(vec[i + 1].second);
        adj[vec[i + 1].second].push_back(vec[i].second);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cmpid++;
      dfs(i);
    }
  }
  int l = 0, r = 1e9 + 7;
  while (l < r) {
    int mid = (l + r) >> 1, cnt = cmpid;
    for (int i = 1; i <= cmpid; i++) {
      for (int e : cmp[i]) {
        if (T[e] <= mid) {
          cnt--;
          break;
        }
      }
    }
    if (cnt <= mid + 1)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
