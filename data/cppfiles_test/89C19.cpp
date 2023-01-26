#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int N = 2e5 + 5;
vector<int> g[N];
bool bud[N];
int n, u, v;
bool dfs(int p, int q) {
  if (p != 1 && g[p].size() == 1) return bud[p] = 0;
  bool &ret = bud[p];
  ret = 0;
  for (int ch : g[p]) {
    if (ch != q) {
      ret |= dfs(ch, p) ^ 1;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 1);
    int buds = 0;
    for (int i = 2; i <= n; ++i) {
      buds += bud[i];
    }
    int leaves = n - buds - 1;
    cout << (bud[1] ? leaves - buds : leaves - buds + 1) << "\n";
  }
  return 0;
}
