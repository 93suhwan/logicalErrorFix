#include <bits/stdc++.h>
using namespace std;
struct node {
  int R, L;
  bool always;
  node(int R, int L, bool always) {
    this->R = R;
    this->L = L;
    this->always = always;
  }
  bool operator<(const node &rhs) const {
    return make_pair(R, L) < make_pair(rhs.R, rhs.L);
  }
};
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; i++) {
    int skill, neat;
    scanf("%d%d", &skill, &neat);
    points[i] = {skill, neat};
  }
  vector<node> s(n, node(INT_MAX, INT_MAX, true));
  for (int i = 0; i < n; i++) {
    if (points[i].first >= d) {
      if (points[i].first >= points[i].second) {
        s[i] = {points[i].first, points[i].second, true};
      } else {
        s[i] = {points[i].second, points[i].first, false};
      }
    } else {
      s[i] = {INT_MAX, INT_MAX, false};
    }
  }
  sort(s.begin(), s.end());
  while (!s.empty() && s.back().L == INT_MAX) s.pop_back();
  if (s.empty()) {
    cout << 0 << endl;
    return 0;
  }
  n = s.size();
  vector<int> dp(n);
  int ans = 0;
  int height = 0;
  for (int i = 0; i < n; i++) {
    height = max(height, s[i].L);
    if (i > 0) dp[i] = dp[i - 1];
    if (s[i].always) {
      ans++;
      continue;
    }
    if (height > s[i].L) continue;
    int best_dp_yet =
        upper_bound(s.begin(), s.end(), node(s[i].L - 1, INT_MAX, 1)) -
        s.begin();
    dp[i] = max(dp[i], dp[best_dp_yet] + 1);
  }
  printf("%d", ans + dp[n - 1]);
  return 0;
}
