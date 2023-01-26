#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
const long long M = 1e11;
int T, n, m;
long long a[N], dp[N][2];
vector<pair<long long, long long> > v1[N], v2[N];
priority_queue<pair<long long, long long> > q;
bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
  if (x.first == y.first) return x.second > y.second;
  return x.first < y.first;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n);
  a[0] = -M;
  a[++n] = M;
  for (int i = 1; i <= n; i++) v1[i].clear(), v2[i].clear();
  for (int i = 1; i <= m; i++) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    int p = lower_bound(a + 1, a + 1 + n, l) - a;
    if (r < a[p]) v1[p].push_back(make_pair(l, r));
  }
  int now = 1;
  while (now <= n) {
    while (!v1[now].size() && now <= n) now++;
    if (now > n) break;
    sort(v1[now].begin(), v1[now].end(), cmp);
    for (auto x : v1[now]) {
      while (q.size() && q.top().first >= x.second) q.pop();
      q.push(make_pair(x.second, x.first));
    }
    while (q.size())
      v2[now].push_back(make_pair(q.top().second, q.top().first)), q.pop();
    now++;
  }
  memset(dp, 127, sizeof(dp));
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    if (!v2[i].size()) {
      dp[i][0] = dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
      continue;
    }
    sort(v2[i].begin(), v2[i].end());
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i] - v2[i][0].second;
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (a[i] - v2[i][0].second) * 2;
    for (int j = 0; j < v2[i].size() - 1; j++) {
      pair<long long, long long> x = v2[i][j], y = v2[i][j + 1];
      dp[i][0] = min(dp[i][0], min(dp[i - 1][0] + (x.first - a[i - 1]) * 2,
                                   dp[i - 1][1] + x.first - a[i - 1]) +
                                   a[i] - y.second);
      dp[i][1] = min(dp[i][1], min(dp[i - 1][0] + (x.first - a[i - 1]) * 2,
                                   dp[i - 1][1] + x.first - a[i - 1]) +
                                   (a[i] - y.second) * 2);
    }
    dp[i][0] =
        min(dp[i][0],
            min(dp[i - 1][0] + (v2[i][v2[i].size() - 1].first - a[i - 1]) * 2,
                dp[i - 1][1] + v2[i][v2[i].size() - 1].first - a[i - 1]));
    dp[i][1] =
        min(dp[i][1],
            min(dp[i - 1][0] + (v2[i][v2[i].size() - 1].first - a[i - 1]) * 2,
                dp[i - 1][1] + v2[i][v2[i].size() - 1].first - a[i - 1]));
  }
  printf("%lld\n", min(dp[n][0], dp[n][1]));
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
