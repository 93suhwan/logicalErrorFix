#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int t, n;
vector<int> g[200010], v;
int dfs(int pos, int par) {
  int cnt = 0;
  for (int i = 0; i < g[pos].size(); ++i)
    if (g[pos][i] != par) cnt += dfs(g[pos][i], pos);
  if (cnt > 0) v.push_back(cnt);
  return (cnt > 0 ? 0 : 1);
}
int main() {
  cin >> t;
  for (int tn = 0; tn < t; ++tn) {
    cin >> n;
    for (int i = 0; i < n + 3; ++i) g[i].clear();
    int x, y;
    for (int i = 0; i < n - 1; ++i) {
      scanf("%d%d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    v.clear();
    dfs(1, 0);
    int ans = v[0];
    for (int i = 1; i <= v.size() - 1; ++i) ans += v[i] - 1;
    cout << ans << endl;
  }
  return 0;
}
