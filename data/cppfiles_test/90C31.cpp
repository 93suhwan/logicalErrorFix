#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e10 + 5;
const int MX = 2e5 + 5;
int t, n, m, l, r;
long long int a[MX], dp[MX][2], cost1, cost2, cost3;
vector<pair<long long int, long long int> > seg[MX];
void getCost(vector<pair<long long int, long long int> > &v, int idx) {
  if (v.empty()) {
    cost1 = cost2 = cost3 = 0;
    return;
  }
  cost1 = (v.back().first - a[idx - 1]) * 2,
  cost2 = v.back().first - a[idx - 1], cost3 = v.back().first - a[idx - 1];
  long long int minR = v.back().second;
  for (int i = (int)v.size() - 1; i; i--) {
    minR = min(minR, v[i].second);
    long long int distL = v[i - 1].first - a[idx - 1], distR = a[idx] - minR;
    cost1 = min(cost1, distL * 2 + distR);
    cost2 = min(cost2, distL + distR);
    cost3 = min(cost3, distL + distR * 2);
  }
}
int main() {
  cin.tie(nullptr), ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    a[n] = inf;
    for (int i = 0; i <= n; i++) seg[i].clear();
    for (int i = 0; i < m; i++) {
      cin >> l >> r;
      int p = lower_bound(a, a + n, l) - a;
      if (p != n && a[p] <= r) continue;
      seg[p].emplace_back(l, r);
    }
    for (int i = 0; i <= n; i++) sort(seg[i].begin(), seg[i].end());
    for (int i = 0; i <= n; i++) {
      long long int minR = inf;
      for (auto &p : seg[i]) minR = min(minR, p.second);
      if (i == 0) {
        if (seg[i].empty())
          dp[i][0] = dp[i][1] = 0;
        else {
          dp[i][0] = a[0] - minR;
          dp[i][1] = (a[0] - minR) * 2;
        }
      } else {
        getCost(seg[i], i);
        long long int costR = 0;
        if (!seg[i].empty()) costR = a[i] - minR;
        dp[i][0] = min(min(cost1, costR) + dp[i - 1][0], cost2 + dp[i - 1][1]);
        dp[i][1] =
            min(min(cost2 * 2, costR * 2) + dp[i - 1][0], cost3 + dp[i - 1][1]);
      }
    }
    cout << dp[n][0] << "\n";
  }
}
