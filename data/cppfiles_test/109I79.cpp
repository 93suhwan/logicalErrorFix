#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
inline int rd() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 300010;
struct edge {
  int v, w, nx;
} e[N << 1];
int hd[N], cnt;
void add(int u, int v, int w) {
  e[++cnt] = (edge){v, w, hd[u]};
  hd[u] = cnt;
}
int qp(int a, int b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
int t, n, m, ans;
const int mod = 998244353;
char c[100010][2];
bool is(char c1, char c2, char c3, char c4) {
  if (c1 == '?')
    ;
  else if (c1 != c3)
    return 0;
  if (c2 == '?')
    ;
  else if (c2 != c4)
    return 0;
  return 1;
}
int dp[2][200010];
int dpp[100010];
int main() {
  n = rd();
  for (int i = 1; i <= n; i++) cin >> c[i][0] >> c[i][1];
  ans = 2;
  for (int i = 1; i <= n; i++)
    if (!is(c[i][0], c[i][1], 'B', 'W')) {
      ans--;
      break;
    }
  for (int i = 1; i <= n; i++)
    if (!is(c[i][0], c[i][1], 'W', 'B')) {
      ans--;
      break;
    }
  dpp[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (is(c[i][0], c[i][1], 'B', 'W')) dpp[i] += dpp[i - 1];
    if (is(c[i][0], c[i][1], 'W', 'B')) dpp[i] += dpp[i - 1];
    dpp[i] %= mod;
  }
  dp[0][100000] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = max(-i, -(n - i + 1)) + 100000;
         j <= min(i, n - i + 1) + 100000; j++) {
      dp[i & 1][j] = 0;
      if (is(c[i][0], c[i][1], 'B', 'W')) dp[i & 1][j] += dp[i & 1 ^ 1][j];
      if (is(c[i][0], c[i][1], 'W', 'B')) dp[i & 1][j] += dp[i & 1 ^ 1][j];
      if (is(c[i][0], c[i][1], 'B', 'B')) dp[i & 1][j] += dp[i & 1 ^ 1][j - 1];
      if (is(c[i][0], c[i][1], 'W', 'W')) dp[i & 1][j] += dp[i & 1 ^ 1][j + 1];
      dp[i & 1][j] %= mod;
      dpp[i] %= mod;
    }
  printf("%lld\n", (ans + dp[n & 1][100000] - dpp[n] + mod) % mod);
  return 0;
}
