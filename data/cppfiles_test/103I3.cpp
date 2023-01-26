#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int mx = 1e7 + 1;
vector<pair<int, int> > adj[20][20];
vector<pair<int, int> > topo;
int cm = 0;
vector<vector<int> > vis(20, vector<int>(20, 0));
void dfs(pair<int, int> st) {
  vis[st.first][st.second] = 1;
  for (pair<int, int> x : adj[st.first][st.second]) {
    if (!vis[x.first][x.second]) {
      dfs(x);
    }
  }
  topo.push_back(st);
}
void dfs2(pair<int, int> st) {
  cm++;
  vis[st.first][st.second] = 2;
  for (pair<int, int> x : adj[st.first][st.second]) {
    if (vis[x.first][x.second] == 1) {
      dfs2(x);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string second[n];
    topo.clear();
    for (int i = 0; i < n; i++) {
      cin >> second[i];
      for (int j = 0; j < m; j++) {
        adj[i][j].clear(), vis[i][j] = 0;
        if (second[i][j] == 'R') {
          if (j + 1 < m) adj[i][j].push_back({i, j + 1});
        } else if (second[i][j] == 'L') {
          if (j - 1 >= 0) adj[i][j].push_back({i, j - 1});
        } else if (second[i][j] == 'U') {
          if (i - 1 >= 0) adj[i][j].push_back({i - 1, j});
        } else {
          if (i + 1 < n) adj[i][j].push_back({i + 1, j});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j]) dfs({i, j});
      }
    }
    reverse(topo.begin(), topo.end());
    int mx = 0;
    int ax, ay;
    for (pair<int, int> x : topo) {
      int i = x.first, j = x.second;
      if (vis[i][j] == 1) {
        cm = 0;
        dfs2({i, j});
        if (cm > mx) {
          ax = i + 1, ay = j + 1;
          mx = cm;
        }
      }
    }
    cout << ax << " " << ay << " " << mx << "\n";
  }
  return 0;
}
