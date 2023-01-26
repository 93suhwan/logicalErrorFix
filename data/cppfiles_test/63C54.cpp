#include <bits/stdc++.h>
using namespace std;
namespace Ruri {
const int infi = 1e9;
const long long infl = 4e18;
inline long long ceil_div(long long a, long long b) { return (a + b - 1) / b; }
inline long long pos_mod(long long a, long long b) { return (a % b + b) % b; }
}  // namespace Ruri
using namespace Ruri;
namespace Read {
inline int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long rl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline double rd() {
  double x;
  scanf("%lf", &x);
  return x;
}
}  // namespace Read
namespace DeBug {}
using namespace DeBug;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> len(n), delta(n), mn_delta(n, 0);
  vector<vector<vector<int> > > pos(n);
  for (int i = 0, bbb = n - 1; i <= bbb; ++i) {
    cin >> s[i];
    len[i] = s[i].length();
    pos[i].resize(2 * len[i] + 1);
    int now = len[i];
    for (int j = 0, bbb = len[i] - 1; j <= bbb; ++j) {
      now += (s[i][j] == '(' ? 1 : -1);
      pos[i][now].push_back(j + 1),
          mn_delta[i] = min(mn_delta[i], now - len[i]);
    }
    delta[i] = now - len[i];
  }
  int ans = 0;
  vector<int> dp(1 << n, -1);
  dp[0] = 0;
  for (int mask = 0, bbb = (1 << n) - 1; mask <= bbb; ++mask)
    if (~dp[mask]) {
      int psum = 0;
      for (int bit = 0, bbb = n - 1; bit <= bbb; ++bit)
        if ((mask >> bit) & 1) psum += delta[bit];
      for (int bit = 0, bbb = (n - 1); bit <= bbb; ++bit)
        if (!((mask >> bit) & 1)) {
          int balance_pos = len[bit] - psum;
          if (psum + mn_delta[bit] < 0) {
            int bound = pos[bit][balance_pos - 1][0];
            int res = (int)(lower_bound(pos[bit][balance_pos].begin(),
                                        pos[bit][balance_pos].end(), bound) -
                            pos[bit][balance_pos].begin());
            ans = max(ans, dp[mask] + res);
            continue;
          }
          int add = 0;
          if (0 <= balance_pos && balance_pos <= 2 * len[bit])
            add = (int)pos[bit][balance_pos].size();
          dp[mask | (1 << bit)] = max(dp[mask | (1 << bit)], dp[mask] + add);
        }
    }
  printf("%d\n", max(ans, dp.back()));
  return 0;
}
