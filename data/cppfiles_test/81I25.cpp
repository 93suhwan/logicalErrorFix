#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; i++) {
    int skill, neat;
    scanf("%d%d", &skill, &neat);
    points[i] = {skill, neat};
  }
  vector<pair<pair<int, int>, int>> s(n);
  for (int i = 0; i < n; i++) {
    if (points[i].first >= d) {
      if (points[i].first >= points[i].second) {
        s[i] = {{points[i].first, points[i].second}, 1};
      } else {
        s[i] = {{points[i].second, points[i].first}, 0};
      }
    } else {
      s[i] = {{INT_MAX, INT_MAX}, 0};
    }
  }
  sort(s.begin(), s.end());
  while (!s.empty() && s.back().first.second == INT_MAX) s.pop_back();
  if (s.empty()) {
    cout << 0 << endl;
    return 0;
  }
  n = s.size();
  vector<int> dp(n);
  int ans = 0;
  int height = 0;
  for (int i = 0; i < n; i++) {
    height = max(height, s[i].first.second);
    if (i > 0) dp[i] = dp[i - 1];
    if (s[i].second) {
      ans++;
      continue;
    }
    if (height > s[i].first.second) continue;
    int best_dp_yet =
        upper_bound(s.begin(), s.end(),
                    make_pair(make_pair(s[i].first.second, INT_MAX), INT_MAX)) -
        s.begin();
    if (best_dp_yet >= 0) dp[i] = max(dp[i], dp[best_dp_yet] + 1);
  }
  printf("%d", ans + dp[n - 1]);
  return 0;
}
