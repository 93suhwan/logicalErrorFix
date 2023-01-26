#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int m, int id, int prev) {
  for (int j = 0; j < adj[id].size(); j++) {
    if (adj[id][j] != prev) {
      cout << id << ' ' << adj[id][j] << endl;
      dfs(adj, m, adj[id][j], id);
    }
  }
}
int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    int s, d;
    cin >> s >> d;
    vector<int> adj[s + 1];
    int cnt;
    vector<int> v(s + 1, 0);
    for (int i = 0; i < d; i++) {
      int j, k, l;
      cin >> j >> k >> l;
      v[k] = 1;
    }
    for (int i = 1; i <= s; i++) {
      if (v[i] == 0) {
        cnt = i;
        break;
      }
    }
    for (int i = 1; i <= s; i++) {
      if (i == cnt) continue;
      cout << cnt << ' ' << i << endl;
    }
  }
}
