#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 1;
const int SQRT = 448;
int cnt[MAX], sz[MAX];
int n;
vector<vector<int> > adj(MAX);
vector<int> dp1[MAX], dp2[MAX];
int tmpdp[SQRT + 10];
void dfs(int node, int par) {
  cnt[node] = sz[node] = 1;
  if (adj[node].size() == 1 && node != 1) cnt[node] = 0;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    dfs(child, node);
    sz[node] += sz[child], cnt[node] += cnt[child];
  }
  dp1[node] = vector<int>(sz[node] + 1, 0),
  dp2[node] = vector<int>(cnt[node] + 1, 0);
}
void dfs2(int node, int par) {
  for (auto &child : adj[node]) {
    if (child == par) continue;
    dfs2(child, node);
    for (int j = 0; j <= min(cnt[node], SQRT); ++j) tmpdp[j] = dp2[node][j] + 1;
    for (int j = 0; j <= min(sz[node], SQRT); ++j) {
      dp1[node][j] += max(1, dp1[child][j] - j);
      if (j >= cnt[node]) continue;
      if (!dp2[node][j] && j) continue;
      for (int j2 = 0; j + j2 + 1 <= min(cnt[node], SQRT) && j2 <= cnt[child];
           ++j2)
        tmpdp[j + j2 + 1] =
            max(tmpdp[j + j2 + 1],
                max(dp2[node][j + j2 + 1] + 1, dp2[node][j] + dp2[child][j2]));
    }
    for (int i = 0; i <= min(cnt[node], SQRT); ++i)
      dp2[node][i] = tmpdp[i], tmpdp[i] = 0;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  dfs2(1, -1);
  int q;
  cin >> q;
  while (q--) {
    int node, k;
    cin >> node >> k;
    if (k <= SQRT) {
      if (k > sz[node])
        cout << adj[node].size() - (node != 1) << "\n";
      else
        cout << dp1[node][k] << "\n";
    } else {
      int ans = 0;
      for (int i = 0; i <= min(cnt[node], SQRT); ++i)
        ans = max(ans, dp2[node][i] - k * i);
      cout << ans << "\n";
    }
  }
  return 0;
}
