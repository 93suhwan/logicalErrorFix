#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}
int dp[5001][8192]{};
class Solution {
 public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n);
    vector<vector<int>> nums(5001);
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      nums[a[i]].push_back(i + 1);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    vector<bool> can(8192);
    can[0] = true;
    for (int i = 1; i <= 5000; ++i) {
      for (int j = 1; j < 8192; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (i == j && !nums[i].empty()) dp[i][j] = min(dp[i][j], nums[i][0]);
        auto it = upper_bound(nums[i].begin(), nums[i].end(), dp[i - 1][i ^ j]);
        if (it != nums[i].end()) dp[i][j] = min(dp[i][j], *it);
        if (dp[i][j] < 0x3f3f3f3f) can[j] = true;
      }
    }
    int ans = 0;
    for (int i = 0; i < 8192; ++i)
      if (can[i]) ans++;
    printf("%d\n", ans);
    for (int i = 0; i < 8192; ++i)
      if (can[i]) printf("%d ", i);
    printf("\n");
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}
