#include <bits/stdc++.h>
using namespace std;
void merge(int i, int j, map<int, int> &mp) {
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second == i) it->second = j;
  }
}
void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, int label,
         map<int, int> &mp) {
  vis[i] = 1;
  mp[i] = label;
  for (auto j : adj[i]) {
    if (!vis[j]) dfs(j, adj, vis, label, mp);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  map<int, int> mp1, mp2;
  vector<vector<int>> adj1(n + 1, vector<int>()), adj2(n + 1, vector<int>());
  while (m1--) {
    int x, y;
    cin >> x >> y;
    adj1[x].push_back(y);
    adj1[y].push_back(x);
  }
  while (m2--) {
    int x, y;
    cin >> x >> y;
    adj2[x].push_back(y);
    adj2[y].push_back(x);
  }
  vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (!vis1[i]) dfs(i, adj1, vis1, i, mp1);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis2[i]) dfs(i, adj2, vis2, i, mp2);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (mp1[i] != mp1[j] && mp2[i] != mp2[j]) {
        merge(mp1[i], mp1[j], mp1);
        merge(mp2[i], mp2[j], mp2);
        ans.push_back({i, j});
      }
    }
  }
  cout << ans.size() << endl;
  for (auto pr : ans) cout << pr.first << " " << pr.second << endl;
  return 0;
}
