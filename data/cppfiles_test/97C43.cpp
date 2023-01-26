#include <bits/stdc++.h>
using namespace std;
vector<int> L[200200];
int ord[2][200200];
int cnt = 0;
int par[200200];
int sum_kids[200200];
int dp[200200];
vector<pair<int, int> > queries[200200];
void dfs(int vx, int p = 0) {
  par[vx] = p;
  for (int i : L[vx])
    if (i != p) {
      dfs(i, vx);
      dp[vx] += dp[i];
    }
  ord[0][cnt++] = vx;
  dp[vx] = max(dp[vx], 1);
  sum_kids[p] += dp[vx];
}
int ans[200200];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    L[a].push_back(b);
    L[b].push_back(a);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int v, k;
    scanf("%d%d", &v, &k);
    queries[k].push_back({v, i});
  }
  dfs(1);
  int sz = n;
  for (int k = 1; k < 200200; k++) {
    for (pair<int, int> i : queries[k - 1]) ans[i.second] = sum_kids[i.first];
    int nu = 0;
    for (int i = 0; i < sz; i++) {
      int vx = ord[(k + 1) % 2][i];
      sum_kids[par[vx]] -= dp[vx];
      dp[vx] = max(1, sum_kids[vx] - k);
      sum_kids[par[vx]] += dp[vx];
      if (dp[vx] > 1) ord[k % 2][nu++] = vx;
    }
    sz = nu;
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}
