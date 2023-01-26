#include <bits/stdc++.h>
using namespace std;
namespace Ruri {
const int infi = 1e9;
const long long infl = 4e18;
}  // namespace Ruri
using namespace Ruri;
namespace Gadgets {
inline long long ceil_div(long long a, long long b) { return (a + b - 1) / b; }
inline long long pos_mod(long long a, long long b) { return (a % b + b) % b; }
}  // namespace Gadgets
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
using namespace Gadgets;
using namespace Read;
using namespace DeBug;
const int MAX_N = 1e5 + 5;
const int mod = 998244353;
void Add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void Minus(int &x, int y) {
  x -= y;
  x += (x >> 31) & mod;
};
void Mul(int &x, int y) { x = 1ll * x * y % mod; }
int n, a[MAX_N];
int dp[2][MAX_N];
vector<int> rec[2];
int main() {
  memset(dp, -1, sizeof(dp));
  int T = ri();
  while (T--) {
    rec[0].clear(), rec[1].clear();
    n = ri();
    for (int i = 1, bbb = n; i <= bbb; ++i) a[i] = ri();
    int ans = 0;
    int now = 1, pre = 0;
    dp[pre][a[n]] = 1;
    rec[pre].push_back(a[n]);
    for (int i = n - 1, bbb = 1; i >= bbb; --i) {
      for (auto val : rec[pre]) {
        int k = (a[i] + val - 1) / val,
            res = 1ll * i * (k - 1) % mod * dp[pre][val] % mod;
        Add(ans, res);
        int now_val = a[i] / k;
        if (dp[now][now_val] == -1)
          rec[now].push_back(now_val), dp[now][now_val] = 0;
        Add(dp[now][now_val], dp[pre][val]);
        dp[pre][val] = -1;
      }
      if (dp[now][a[i]] == -1) rec[now].push_back(a[i]), dp[now][a[i]] = 0;
      Add(dp[now][a[i]], 1), rec[pre].clear();
      swap(pre, now);
    }
    for (auto val : rec[pre]) dp[pre][val] = -1;
    printf("%lld\n", pos_mod(ans, mod));
  }
  return 0;
}
