#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXM = 800005;
int a[MAXN];
int n, m;
vector<pair<int, int>> G[MAXN];
long long dp[MAXN][2];
int search(int x) {
  int l = 1, r = n;
  while (l < r) {
    int mid = l + r >> 1;
    if (a[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  a[++n] = 2e9 + 7;
  for (int i = 1; i <= n; i++) G[i].clear();
  int dist = 0;
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    int x = search(l);
    if (a[x] <= r) continue;
    if (x > 1)
      G[x].push_back({l, r});
    else
      dist = max(dist, a[x] - r);
  }
  dp[1][0] = dist * 2;
  dp[1][1] = dist;
  for (int i = 2; i <= n; i++) {
    long long x = a[i - 1], y = a[i];
    G[i].push_back({x, 0});
    sort(G[i].begin(), G[i].begin() + G[i].size());
    G[i].push_back({0, y});
    long long r_cost = 0;
    dp[i][0] = dp[i][1] = 1e18;
    for (int j = G[i].size() - 2; j >= 0; --j) {
      r_cost = max(r_cost, y - G[i][j + 1].second);
      long long l_cost = G[i][j].first - x;
      dp[i][0] = min(dp[i][0], min(dp[i - 1][0] + l_cost + r_cost * 2,
                                   dp[i - 1][1] + l_cost * 2 + r_cost * 2));
      dp[i][1] = min(dp[i][1], min(dp[i - 1][0] + l_cost + r_cost,
                                   dp[i - 1][1] + l_cost * 2 + r_cost));
    }
  }
  printf("%lld\n", dp[n][0]);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) solve();
  return 0;
}
