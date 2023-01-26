#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;
const int maxk = 455;
inline long long read() {
  long long ans = 0;
  char ch = getchar(), las = ' ';
  while (!isdigit(ch)) las = ch, ch = getchar();
  while (isdigit(ch)) ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  if (las == '-') ans = -ans;
  return ans;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void MYFILE() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
int n;
long long a[maxn], sum[maxn];
inline long long S(int L, int R) { return sum[R] - sum[L - 1]; }
long long dp[maxn][maxk];
inline int DP() {
  int K = 1;
  while ((K + 1) * (K + 2) / 2 <= n) ++K;
  for (int i = 1; i <= K; ++i) dp[n + 1][i] = -1;
  dp[n + 1][0] = INF;
  for (int i = n; i; --i)
    for (int j = 1; j <= K; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (S(i, i + j - 1) < dp[i + j][j - 1])
        dp[i][j] = max(dp[i][j], S(i, i + j - 1));
    }
  for (int i = K; i; --i)
    if (~dp[1][i]) return i;
  return 0;
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; ++i) {
      a[i] = read();
      sum[i] = sum[i - 1] + a[i];
    }
    write(DP()), puts("");
  }
  return 0;
}
