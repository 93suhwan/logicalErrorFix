#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
int __FAST_IO__ = []() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  return 0;
}();
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < (N); ++i) cin >> v[i];
    vector<vector<vector<int>>> dp(
        N, vector<vector<int>>(2, vector<int>(2, INT_MAX)));
    vector<vector<vector<pair<int, int>>>> pr(
        N,
        vector<vector<pair<int, int>>>(2, vector<pair<int, int>>(2, {-1, -1})));
    dp[0][1][0] = dp[0][1][1] = INT_MIN;
    for (int i = (1); i < (N); ++i) {
      for (int pos = 0; pos < (2); ++pos)
        for (int sign = 0; sign < (2); ++sign) {
          if (dp[i - 1][pos][sign] == INT_MAX) continue;
          int x = sign ? -v[i - 1] : v[i - 1];
          int y = dp[i - 1][pos][sign];
          if (!pos) swap(x, y);
          for (int nsign = 0; nsign < (2); ++nsign) {
            int z = nsign ? -v[i] : v[i];
            if (z > x) {
              if (dp[i][1][nsign] > y) {
                dp[i][1][nsign] = y;
                pr[i][1][nsign] = {pos, sign};
              }
            } else if (z > y) {
              if (dp[i][0][nsign] > x) {
                dp[i][0][nsign] = x;
                pr[i][0][nsign] = {pos, sign};
              }
            }
          }
        }
    }
    for (int pos = 0; pos < (2); ++pos)
      for (int sign = 0; sign < (2); ++sign) {
        if (pr[N - 1][pos][sign].first != -1) {
          printf("YES\n");
          int p = pos, s = sign;
          vector<int> ans;
          for (int i = (N - 1); i >= 0; --i) {
            ans.push_back(s ? -v[i] : v[i]);
            auto next = pr[i][p][s];
            p = next.first, s = next.second;
          }
          for (int i = (ans.size() - 1); i >= 0; --i) printf("%d ", ans[i]);
          printf("\n");
          goto finish;
        }
      }
    printf("NO\n");
  finish:;
  }
  return 0;
}
