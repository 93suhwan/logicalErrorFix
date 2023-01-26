#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a, b;
vector<int> edg[100005];
bool vis[100005];
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < edg[u].size(); i++) {
    int v = edg[u][i];
    if (!vis[v]) dfs(v);
  }
}
void reset(int n) {
  a.clear();
  b.clear();
  for (int i = 0; i < n; i++) {
    edg[i].clear();
    vis[i] = 0;
  }
}
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back({x, i});
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b.push_back({x, i});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for (int i = 1; i < a.size(); i++) {
      edg[a[i].second].push_back(a[i - 1].second);
      edg[b[i].second].push_back(b[i - 1].second);
    }
    dfs(a[0].second);
    dfs(b[0].second);
    for (int i = 0; i < n; i++) cout << vis[i];
    cout << endl;
    reset(n);
  }
  return 0;
}
