#include <bits/stdc++.h>
using namespace std;
int n, d;
vector<int> adj[1000005];
int ans[1000005];
int a[1000005];
bool vis[1000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int te;
  cin >> te;
  while (te--) {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) adj[i].clear(), ans[i] = 0, vis[i] = false;
    for (int i = 1; i <= d; ++i) {
      for (int j = i + d; j <= n; j += d) {
        adj[j - d].push_back(j);
      }
      int ls = (d - i);
      ls = n - ls;
      adj[ls].push_back(i);
    }
    queue<pair<int, int> > q;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] == 0) {
        q.push({i, 0});
      }
    }
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (vis[cur.first]) continue;
      vis[cur.first] = true;
      ans[cur.first] = cur.second;
      for (auto i : adj[cur.first]) {
        if (!vis[i]) {
          q.push({i, cur.second + 1});
        }
      }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 1) {
        if (!ans[i]) {
          res = -1;
          break;
        } else {
          res = max(res, ans[i]);
        }
      }
    }
    cout << res << "\n";
  }
}
