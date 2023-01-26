#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, MAX = 200001, MOD = 1000000007;
int n, m;
set<int, greater<int>> adj[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (*adj[i].begin() > i) cnt++;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, u, v;
    cin >> a;
    if (a == 1) {
      cin >> u >> v;
      if (*adj[u].begin() > u) cnt--;
      adj[u].insert(v);
      if (*adj[u].begin() > u) cnt++;
      if (*adj[v].begin() > v) cnt--;
      adj[v].insert(u);
      if (*adj[v].begin() > v) cnt++;
    } else if (a == 2) {
      cin >> u >> v;
      if (*adj[u].begin() > u) cnt--;
      adj[u].erase(v);
      if (*adj[u].begin() > u) cnt++;
      if (*adj[v].begin() > v) cnt--;
      adj[v].erase(u);
      if (*adj[v].begin() > v) cnt++;
    } else {
      cout << n - cnt << '\n';
    }
  }
}
