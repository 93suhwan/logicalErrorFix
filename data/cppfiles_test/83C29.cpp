#include <bits/stdc++.h>
template <class T>
inline T max(const T &x, const T &y) {
  return x > y ? x : y;
}
template <class T>
inline T min(const T &x, const T &y) {
  return x < y ? x : y;
}
template <class T>
inline bool chkmax(T &x, const T &y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool chkmin(T &x, const T &y) {
  return x > y ? x = y, true : false;
}
inline long long read() {
  register long long x = 0, v = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') v = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * v;
}
const long long MAXN = 10000;
long long n, ans, dp[MAXN | 1], minn[20][MAXN | 1], lg[MAXN | 1];
char str[MAXN + 5];
inline long long calc(long long l, long long r) {
  return 1ll * (l + r) * (r - l + 1) / 2;
}
namespace SA {
long long tax[MAXN | 1], rnk[MAXN | 1], tp[MAXN | 1], sa[MAXN | 1],
    height[MAXN | 1];
void clear() {
  memset(tax, 0, sizeof(tax));
  memset(rnk, 0, sizeof(rnk));
  memset(tp, 0, sizeof(tp));
  memset(sa, 0, sizeof(sa));
  memset(height, 0, sizeof(height));
}
void Q_sort(long long lim) {
  for (long long i = 1; i <= lim; ++i) tax[i] = 0;
  for (long long i = 1; i <= n; ++i) ++tax[rnk[i]];
  for (long long i = 1; i <= lim; ++i) tax[i] += tax[i - 1];
  for (long long i = n; i >= 1; --i) sa[tax[rnk[tp[i]]]--] = tp[i];
}
void get_SA() {
  long long m = 75;
  for (long long i = 1; i <= n; ++i) {
    rnk[i] = str[i] - 'a' + 1;
    tp[i] = i;
  }
  Q_sort(m);
  for (long long w = 1, p = 0; p < n; m = p, w <<= 1) {
    p = 0;
    for (long long i = 1; i <= w; ++i) tp[++p] = n - i + 1;
    for (long long i = 1; i <= n; ++i)
      if (sa[i] > w) tp[++p] = sa[i] - w;
    Q_sort(m);
    std::swap(rnk, tp);
    rnk[sa[1]] = p = 1;
    for (long long i = 2; i <= n; ++i)
      rnk[sa[i]] =
          (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + w] == tp[sa[i] + w])
              ? p
              : ++p;
  }
}
void get_HE() {
  for (long long i = 1; i <= n; ++i) {
    long long j = height[rnk[i - 1]];
    if (j) --j;
    while (str[sa[rnk[i] - 1] + j] == str[i + j]) ++j;
    height[rnk[i]] = j;
  }
  lg[1] = 0;
  for (long long i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
  for (long long i = 1; i <= n; ++i) minn[0][i] = height[i];
  for (long long i = 1; i < 20; ++i) {
    for (long long j = 1; j + (1 << i) - 1 <= n; ++j) {
      minn[i][j] = min(minn[i - 1][j], minn[i - 1][j + (1 << i - 1)]);
    }
  }
}
long long query(long long l, long long r) {
  long long len = lg[r - l + 1];
  return min(minn[len][l], minn[len][r - (1 << len) + 1]);
}
}  // namespace SA
using namespace SA;
signed main() {
  long long cases = read();
  while (cases--) {
    n = read();
    scanf("%s", str + 1);
    clear();
    get_SA();
    get_HE();
    memset(dp, 0, sizeof(dp));
    dp[1] = n;
    ans = n;
    for (long long i = 2; i <= n; ++i) {
      dp[i] = (n - i + 1);
      for (long long j = 1; j < i; ++j) {
        if (rnk[j] > rnk[i]) continue;
        long long tmp = (n - i + 1) - query(rnk[j] + 1, rnk[i]);
        chkmax(dp[i], dp[j] + tmp);
      }
      chkmax(ans, dp[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
