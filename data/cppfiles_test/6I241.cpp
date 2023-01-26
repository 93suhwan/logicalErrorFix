#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<priority_queue<long long int>> adj(n + 1);
  int u, v;
  while (m--) {
    cin >> u >> v;
    adj[u].push(v);
    adj[v].push(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (adj[i].empty())
      ans++;
    else if (adj[i].top() < i)
      ans++;
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> u >> v;
      if (adj[u].empty() or (adj[u].top() < u and u < v)) ans--;
      if (adj[v].empty() or (adj[v].top() < v and v < u)) ans--;
      adj[u].push(v);
      adj[v].push(u);
    } else if (t == 2) {
      cin >> u >> v;
      if (adj[u].top() == v) {
        adj[u].pop();
      } else if (adj[v].top() == u) {
        adj[v].pop();
      }
      if (adj[u].empty() or (adj[u].top() < u and u < v)) ans++;
      if (adj[v].empty() or (adj[v].top() < v and v < u)) ans++;
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}
