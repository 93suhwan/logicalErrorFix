#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, int> s[500005];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; i++) {
    int skill, neat;
    scanf("%d%d", &skill, &neat);
    points[i] = {skill, neat};
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (points[i].first >= d) {
      if (points[i].first >= points[i].second) {
        s[m++] = {{points[i].first, points[i].second}, 1};
      } else {
        s[m++] = {{points[i].second, points[i].first}, 0};
      }
    }
  }
  sort(s, s + m);
  if (m == 0) {
    cout << 0 << endl;
    return 0;
  }
  n = m;
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
        upper_bound(s, s + m,
                    make_pair(make_pair(s[i].first.second, INT_MAX), INT_MAX)) -
        s - 1;
    if (best_dp_yet < 0) best_dp_yet = 0;
    dp[i] = max(dp[i], dp[best_dp_yet] + 1);
  }
  printf("%d\n", ans + dp[n - 1]);
  return 0;
}
