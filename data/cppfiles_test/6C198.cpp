#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  init_code();
  int t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n + 1, std::set<int>());
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      if (v > u) {
        graph[u].insert(v);
      } else
        graph[v].insert(u);
    }
    int q;
    cin >> q;
    int prevtype = -1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      set<int> &s = graph[i];
      if (s.size() > 0) {
        ans++;
      }
    }
    while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
        int u, v;
        cin >> u >> v;
        if (v > u) {
          if (graph[u].size() == 0) {
            ans++;
          }
          graph[u].insert(v);
        } else {
          if (graph[v].size() == 0) ans++;
          graph[v].insert(u);
        }
      } else if (type == 2) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
          graph[v].erase(u);
          if (graph[v].size() == 0) {
            ans--;
          }
        } else {
          graph[u].erase(v);
          if (graph[u].size() == 0) {
            ans--;
          }
        }
      } else if (type == 3) {
        cout << n - ans << endl;
      }
      prevtype = type;
    }
  }
}
