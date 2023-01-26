#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long inf = 8e18;
const int LOG = 20;
long long pw(long long a, long long b, long long M = mod, long long ret = 1) {
  while (b) {
    ret = ret * (b & 1 ? a : 1) % M, a = a * a % M, b >>= 1;
  }
  return ret;
}
int n, A[N], mn[1 << LOG], sum[1 << LOG], dp[2][1 << LOG];
char C[N];
string s[LOG];
map<int, int> cnt[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", C);
    s[i] = C;
    for (int j = 0; j < (int)s[i].size(); j++) {
      A[i] += (s[i][j] == '(' ? 1 : -1);
      mn[i] = min(mn[i], A[j]);
      cnt[i][A[i]]++;
    }
  }
  fill(dp[0], dp[0] + (1 << LOG), -1e9);
  for (int mask = 1; mask < 1 << n; mask++) {
    sum[mask] =
        sum[mask - (1 << (__builtin_ctz(mask)))] + A[__builtin_ctz(mask)];
  }
  dp[0][0] = dp[1][0] = 0;
  int tot = 0;
  for (int mask = 1; mask < 1 << n; mask++) {
    for (int i = 0; i < n; i++) {
      if (!(mask >> i & 1)) {
        continue;
      }
      int mask2 = mask ^ (1 << i);
      if (sum[mask2] >= -mn[i]) {
        dp[0][mask] = max(dp[0][mask], dp[0][mask2] + cnt[i][-sum[mask2]]);
      }
      dp[1][mask] = max(dp[1][mask], dp[0][mask2] + cnt[i][-sum[mask2]]);
    }
    tot = max(tot, dp[1][mask]);
  }
  printf("%d", tot);
  return 0;
}
