#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 4;
const int Base = 127, MOD = 998244353;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
template <typename Type>
inline void chkmax(Type &a, const Type &b) {
  if (a < b) a = b;
}
int n, m, dp[MAXN];
char ch[MAXN];
int sa[MAXN], rk[MAXN];
int tp[MAXN], bucket[MAXN];
int height[MAXN];
int table[MAXN][20], lg[MAXN];
inline void Radixsort() {
  for (int i = 0; i <= m; ++i) bucket[i] = 0;
  for (int i = 1; i <= n; ++i) ++bucket[rk[i]];
  for (int i = 1; i <= m; ++i) bucket[i] += bucket[i - 1];
  for (int i = n; i >= 0; --i) sa[bucket[rk[tp[i]]]--] = tp[i];
}
inline void Suffixsort() {
  int i, j, k;
  m = 127;
  memset(sa + 1, 0, sizeof(int) * n);
  memset(rk + 1, 0, sizeof(int) * n);
  memset(tp + 1, 0, sizeof(int) * n);
  memset(height + 1, 0, sizeof(int) * n);
  for (i = 1; i <= n; ++i) rk[i] = ch[i], tp[i] = i;
  Radixsort();
  for (k = 1; k <= n; k <<= 1) {
    j = 0;
    for (i = 1; i <= k; ++i) tp[++j] = n - k + i;
    for (i = 1; i <= n; ++i)
      if (sa[i] > k) tp[++j] = sa[i] - k;
    Radixsort();
    memcpy(tp, rk, sizeof(int) * (n + 1));
    rk[sa[1]] = j = 1;
    for (i = 2; i <= n; ++i)
      rk[sa[i]] =
          (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + k] == tp[sa[i - 1] + k])
              ? j
              : ++j;
    if (j == n) break;
    m = j;
  }
  for (i = 1, k = 0; i <= n; ++i) {
    k -= (bool)k;
    j = sa[rk[i] - 1];
    while (ch[i + k] == ch[j + k]) ++k;
    height[rk[i]] = k;
  }
  for (lg[0] = -1, i = 1; i <= n; ++i)
    lg[i] = lg[i >> 1] + 1, table[i][0] = height[i];
  for (j = 1; j <= lg[n]; ++j)
    for (i = 1; i + (1 << j) - 1 <= n; ++i)
      table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}
inline int lcp(int l, int r) {
  l = rk[l];
  r = rk[r];
  if (l == r) return m - sa[l] + 1;
  if (l > r) swap(l, r);
  ++l;
  int x = lg[r - l + 1];
  return min(table[l][x], table[r - (1 << x) + 1][x]);
}
inline void solve() {
  int i, j;
  n = read();
  scanf("%s", ch + 1);
  Suffixsort();
  for (i = 1; i <= n; ++i) dp[i] = 0;
  dp[1] = n;
  for (i = 2; i <= n; ++i) {
    dp[i] = n - i + 1;
    for (j = 1; j < i; ++j) {
      int l = lcp(i, j);
      if (ch[i + l] < ch[j + l]) continue;
      chkmax(dp[i], dp[j] + n - (i + l) + 1);
    }
  }
  int ans = 0;
  for (i = 1; i <= n; ++i) chkmax(ans, dp[i]);
  printf("%d\n", ans);
}
int main() {
  for (int T = read(); T; --T) solve();
  return 0;
}
