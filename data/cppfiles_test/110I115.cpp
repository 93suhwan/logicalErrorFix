#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5;
int n, t, dp[mxn];
vector<int> adj[mxn], ans;
bool vis[mxn], act[mxn], cycle;
void dfs(int u) {
  vis[u] = 1;
  act[u] = 1;
  for (int a : adj[u]) {
    if (act[a]) {
      cout << "-1\n";
      cycle = true;
    } else {
      if (!vis[a] && !cycle) {
        dfs(a);
      }
    }
  }
  act[u] = 0;
  ans.push_back(u);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int c;
        cin >> c;
        c--;
        adj[c].push_back(i);
      }
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(i);
      }
    }
    if (!cycle) {
      reverse(ans.begin(), ans.end());
      fill(dp, dp + n, 1);
      int ct = 0;
      for (int i = 0; i < n; i++) {
        for (int a : adj[ans[i]]) {
          if (a > ans[i]) {
            dp[a] = max(dp[a], dp[ans[i]]);
          } else {
            dp[a] = max(dp[a], dp[ans[i]] + 1);
          }
        }
        ct = max(ct, dp[ans[i]]);
      }
      cout << ct << "\n";
    }
    for (int i = 0; i < n; i++) {
      adj[i].clear();
    }
    ans.clear();
    fill(vis, vis + n, false);
    cycle = false;
  }
}
