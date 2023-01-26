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
const int N = 101;
int f[N][N][N];
int n, k, m, mod;
int fac[N];
inline int Add(int x, int y) { return (x + y) % mod; }
inline int Mul(int x, int y) { return 1ll * x * y % mod; }
int Cc[101][101];
void pre() {
  fac[0] = 1;
  for (int i = 1; i <= 100; ++i) fac[i] = Mul(fac[i - 1], i);
  Cc[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    Cc[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      Cc[i][j] = Add(Cc[i - 1][j - 1], Cc[i - 1][j]);
    }
  }
}
inline int C(int x, int y) { return Cc[x][y]; }
int nn, mm, kk;
int dfs(int n, int m, int k) {
  if (n == 0) {
    if (k == 0) return 1;
    return 0;
  }
  if (n == 1) {
    if (k == 1 && m == 1) return 1;
    if (!k && m != 1) return 1;
    return 0;
  }
  if (m == 1) {
    if (k == 1) return fac[n];
    return 0;
  }
  if (~f[n][m][k]) return f[n][m][k];
  if (k > n) return 0;
  if (n - m + mm < k) return 0;
  if (n - k + n / 2 < k) return 0;
  int res = 0;
  for (int u = 1; u <= n; ++u) {
    int tmp = 0;
    for (int v = 0; v <= k; ++v) {
      tmp = Add(tmp, Mul(dfs(u - 1, m - 1, v), dfs(n - u, m - 1, k - v)));
    }
    tmp = Mul(tmp, C(n - 1, u - 1));
    res = Add(res, tmp);
  }
  f[n][m][k] = res;
  return f[n][m][k];
}
signed main() {
  scanf("%d%d%d%d", &n, &m, &k, &mod);
  nn = n;
  mm = m;
  kk = k;
  memset(f, -1, sizeof f);
  pre();
  printf("%d\n", dfs(n, m, k));
  return 0;
}
