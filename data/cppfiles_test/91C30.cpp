#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 998244353;
int t, n;
int a[MAXN];
vector<int> dp[2];
long long cnt[2][MAXN];
int main() {
  scanf("%d", &t);
  while (t--) {
    int pos = 0;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = n; i; --i) {
      pos ^= 1;
      dp[pos].push_back(a[i]);
      cnt[pos][a[i]] = 1;
      int last = a[i];
      for (auto it : dp[pos ^ 1]) {
        int minn = ceil(1.0 * a[i] / it);
        int st = a[i] / minn;
        int y = cnt[pos ^ 1][it];
        cnt[pos][st] += y;
        if (st != last) {
          dp[pos].push_back(st), last = st;
        }
        ans += (1ll * i * y) * (minn - 1);
      }
      for (auto x : dp[pos ^ 1]) cnt[pos ^ 1][x] = 0;
      dp[pos ^ 1].clear();
      ans %= MOD;
    }
    printf("%lld\n", ans);
    for (auto x : dp[0]) cnt[0][x] = 0;
    for (auto x : dp[1]) cnt[1][x] = 0;
    dp[0].clear();
    dp[1].clear();
  }
  return 0;
}
