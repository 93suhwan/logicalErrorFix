#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
char val[N];
int n, k, lft[N], done[N], dup[N], rt[N], depth[N], ord[N];
vector<int> order;
string ans, ans2;
void dfs(int node = 1, int par = 1) {
  depth[node] = depth[par] + 1;
  if (lft[node]) dfs(lft[node], node);
  order.push_back(node);
  ord[node] = order.size() - 1;
  ans.push_back(val[node]);
  if (rt[node]) dfs(rt[node], node);
}
void dfs2(int node, int &dep, int ynf3) {
  if (lft[node]) dfs2(lft[node], dep, ynf3);
  if (dep > depth[node]) {
    done[ord[node]] = 1;
    dep = depth[node];
  } else if (dup[ord[node]] && depth[node] - dep <= k && ynf3) {
    k -= depth[node] - dep;
    done[ord[node]] = 1;
    dep = depth[node];
  }
  if (rt[node]) dfs2(rt[node], dep, done[ord[node]]);
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  string st;
  cin >> st;
  for (int i = 1; i <= n; i++) {
    val[i] = st[i - 1];
    cin >> lft[i] >> rt[i];
  }
  dfs();
  dup[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (ans[i] == ans[i + 1])
      dup[i] = dup[i + 1];
    else if (ans[i] < ans[i + 1])
      dup[i] = 1;
  }
  int dep = 0;
  dfs2(1, dep, 1);
  for (int i = 0; i < ans.size(); i++) {
    ans2.push_back(ans[i]);
    if (done[i]) ans2.push_back(ans[i]);
  }
  cout << ans2;
}
