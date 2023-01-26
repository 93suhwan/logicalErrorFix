#include <bits/stdc++.h>
using namespace std;
int N;
char S[23][400005];
vector<int> zhi[23];
int vvv[23];
int dp[(1 << 20) + 3];
inline int countOne(const vector<int>& zhi, int x) {
  auto iter1 = lower_bound(zhi.begin(), zhi.end(), x);
  auto iter2 = upper_bound(zhi.begin(), zhi.end(), x);
  int ret = iter2 - iter1;
  if (x == 0) --ret;
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%s", S[i]);
    int val = 0;
    zhi[i].push_back(-val);
    for (int j = 0; S[i][j]; ++j) {
      if (S[i][j] == '(')
        ++val;
      else
        --val;
      if (val <= -*zhi[i].rbegin()) zhi[i].push_back(-val);
    }
    vvv[i] = val;
  }
  int ans = 0;
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int f = 1; f < (1 << N); ++f) {
    int s = 0;
    for (int i = 0; i < N; ++i)
      if (f & (1 << i)) s += vvv[i];
    for (int i = 0; i < N; ++i)
      if ((f & (1 << i)) && dp[f ^ (1 << i)] != -1) {
        int tmp = dp[f ^ (1 << i)];
        int now = tmp + countOne(zhi[i], s - vvv[i]);
        if (-*zhi[i].rbegin() + s - vvv[i] < 0) {
          ans = max(ans, now);
          continue;
        }
        dp[f] = max(dp[f], now);
      }
  }
  ans = max(ans, dp[(1 << N) - 1]);
  printf("%d\n", ans);
  return 0;
}
