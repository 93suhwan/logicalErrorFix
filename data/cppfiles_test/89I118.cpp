#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1);
vector<int> eg[200005];
int fa[200005], bud[200005], cnt, sum = 0;
void dfs(int x) {
  bud[x] = 1;
  if (x == 1) bud[x] = 0;
  if (eg[x].empty()) bud[x] = 0, cnt++;
  for (int i : eg[x]) {
    if (i == fa[x]) continue;
    if (!eg[i].empty()) bud[x] = 0;
    dfs(i);
  }
  if (bud[x]) sum += eg[x].size() + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      eg[i].clear();
      bud[i] = 0;
      fa[i] = i;
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      eg[u].push_back(v);
    }
    cnt = sum = 0;
    dfs(1);
    bud[1] = 0;
    for (int i = 1; i <= n; i++) {
      cnt -= bud[i];
    }
    if (sum == n - 1) cnt++;
    cout << cnt << '\n';
  }
}
