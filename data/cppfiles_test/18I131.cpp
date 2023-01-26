#include <bits/stdc++.h>
using namespace std;
int n, d;
vector<int> adj[1000005];
int ans[100005];
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
      int cur = i;
      for (int j = i + d; j <= n; j += d) {
        adj[j].push_back(j - d);
        cur = j;
      }
      int nx = (cur + d) % n;
      if (cur != nx) {
        adj[nx].push_back(cur);
      }
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
      vis[cur.first] = true;
      q.pop();
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
