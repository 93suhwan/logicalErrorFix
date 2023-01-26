#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<vector<vector<int>>> adj(n + 1);
    while (q--) {
      string type;
      int u, v;
      cin >> u >> v >> type;
      if (type == "imposter") {
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
      } else {
        adj[u].push_back({v, 2});
        adj[v].push_back({u, 2});
      }
    }
    vector<int> color(n + 1, -1);
    queue<int> que;
    int ans = 0;
    bool contra = false;
    for (int i = 1; i <= n; i++) {
      int numCol1 = 0, numCol2 = 0;
      if (color[i] == -1) {
        que.push(i);
        color[i] = 1;
        while (!que.empty()) {
          int node = que.front();
          if (color[node] == 1)
            numCol1++;
          else
            numCol2++;
          que.pop();
          for (auto nbr : adj[node]) {
            int v = nbr[0], type = nbr[1];
            if (color[v] != -1) {
              if (type == 1 && color[v] == color[node]) contra = true;
              if (type == 2 && color[v] != color[node]) contra = true;
              continue;
            }
            if (type == 1)
              color[v] = 1 - color[node];
            else
              color[v] = color[node];
            que.push(v);
          }
        }
        ans += max(numCol2, numCol1);
      }
    }
    if (contra)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
