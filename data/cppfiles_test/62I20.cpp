#include <bits/stdc++.h>
namespace imzzy {
class fastin {
 private:
  int _ch, _f;

 public:
  inline fastin& operator>>(char& c) {
    c = getchar();
    return *this;
  }
  template <typename _Tp>
  inline fastin& operator>>(_Tp& _x) {
    _x = 0;
    while (!isdigit(_ch)) _f |= (_ch == 45), _ch = getchar();
    while (isdigit(_ch))
      _x = (_x << 1) + (_x << 3) + (_ch ^ 48), _ch = getchar();
    _f && (_x = -_x, _f = 0);
    return *this;
  }
  fastin() { _ch = _f = 0; }
} fin;
}  // namespace imzzy
using namespace imzzy;
const long long mod = 1000000007ll, inf = 2020000007ll, debug = 0;
const int maxn = 100004, maxm = 2504;
char s[22][maxn];
int len[22], dep[22], last[22];
int cnt[22][maxn];
int dp[2][1 << 21];
signed main() {
  register int T = 1;
  while (T--) {
    int n;
    fin >> n;
    for (register int i = 1; i <= n; ++i) scanf("%s", s[i]);
    for (register int i = 1; i <= n; ++i) {
      int now = 0;
      len[i] = strlen(s[i]);
      for (register int j = 0; j < len[i]; ++j) {
        if (s[i][j] == '(')
          ++now;
        else
          --now;
        if (now < dep[i]) dep[i] = now;
        if (now == dep[i]) ++cnt[i][-dep[i]];
      }
      last[i] = now;
    }
    int ans = 0;
    for (register int i = 1; i < 1 << n; ++i) {
      int sum = 0;
      for (register int j = 1; j <= n; ++j)
        if (i & (1 << (j - 1))) sum += last[j];
      for (register int j = 1; j <= n; ++j)
        if (i & (1 << (j - 1))) {
          if (sum - last[j] + dep[j] == 0)
            dp[0][i] =
                std::max(dp[0][i], dp[0][i ^ (1 << (j - 1))] + cnt[j][-dep[j]]);
          if (sum - last[j] + dep[j] > 0)
            dp[0][i] = std::max(dp[0][i], dp[0][i ^ (1 << (j - 1))]);
          if (sum - last[j] + dep[j] < 0 && sum - last[j] >= 0)
            dp[1][i] = std::max(
                dp[1][i], dp[0][i ^ (1 << (j - 1))] + cnt[j][sum - last[j]]);
        }
      ans = std::max(ans, std::max(dp[0][i], dp[1][i]));
    }
    std::cout << ans;
  }
  return 0;
}
