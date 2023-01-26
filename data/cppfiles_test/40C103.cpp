#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int n, m, q, cnt[N];
bool seen[N];
vector<int> G[N], H[N];
pair<int, int> Q[N];
void DFS(int u) {
  seen[u] = true;
  for (int v : G[u]) {
    if (!seen[v]) {
      H[u].push_back(v);
      H[v].push_back(u);
      DFS(v);
    }
  }
}
int p[N];
void DFS2(int u) {
  for (int v : H[u]) {
    if (p[v] == -1) {
      p[v] = u;
      DFS2(v);
    }
  }
}
vector<int> path;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> Q[i].first >> Q[i].second;
    Q[i].first--;
    Q[i].second--;
    cnt[Q[i].first]++, cnt[Q[i].second]++;
  }
  int odd = 0;
  for (int i = 0; i < n; i++) odd += cnt[i] % 2;
  if (odd == 0) {
    cout << "YES\n";
    DFS(0);
    for (int i = 0; i < q; i++) {
      for (int j = 0; j < n; j++) p[j] = -1;
      p[Q[i].second] = Q[i].second;
      DFS2(Q[i].second);
      path.clear();
      int u = Q[i].first;
      while (u != Q[i].second) {
        path.push_back(u);
        u = p[u];
      }
      path.push_back(Q[i].second);
      cout << path.size() << "\n";
      for (int v : path) cout << v + 1 << " ";
      cout << "\n";
    }
  } else {
    cout << "NO\n";
    cout << odd / 2 << "\n";
  }
  return 0;
}
