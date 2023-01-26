#include <bits/stdc++.h>
#pragma GCC optimize(2)
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
const int N = 2001, p = 998244353;
int f[2][N][101], n, k, b[N], fac[N], inv[N], L[N], R[N], R2[N];
long long sum[2][N][101];
int qp(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % p;
    x = 1ll * x * x % p;
    y >>= 1;
  }
  return ans;
}
int C(int x, int y) {
  if (x < 0 || y < 0 || x < y) return 0;
  return 1ll * fac[x] * inv[y] % p * inv[x - y] % p;
}
signed main() {
  cin >> n >> k;
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % p;
  inv[n] = qp(fac[n], p - 2) % p;
  for (int i = n - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
  for (int i = 1; i <= n; i++)
    cin >> b[i], L[i] = max(0, b[i] - k), R[i] = min(n, k + b[i]),
                 R2[i] = min(n, L[i] + 2 * k);
  bool op = 0;
  f[0][0][0] = 1;
  for (int i = 0; i <= 2 * k; i++) sum[0][i][0] = 1;
  long long tmp;
  int xx;
  for (int i = 1; i <= n; i++) {
    op ^= 1;
    if (i >= 2)
      for (int x = L[i - 2]; x <= R2[i - 2]; x++)
        for (int j = x; j <= i - 2; j++)
          f[op][j][x - L[i - 2]] = sum[op][j][x - L[i - 2]] = 0;
    for (int x = L[i]; x <= R2[i]; x++)
      for (int j = x; j <= i; j++) {
        int x1 = x - L[i - 1];
        xx = x - L[i];
        if (x <= R[i]) {
          tmp = 0;
          if (x1 >= 0 && j && x1 <= 2 * k)
            tmp = 1ll * (j - x) * f[op ^ 1][j - 1][x1];
          if (x1 >= 0 && x1 <= 2 * k) tmp += 1ll * j * f[op ^ 1][j][x1];
          if (x1 - 1 >= 0 && j) tmp += sum[op ^ 1][j - 1][min(2 * k, x1 - 1)];
          f[op][j][xx] = tmp % p;
        }
        if (xx)
          sum[op][j][xx] = sum[op][j][xx - 1] + f[op][j][xx];
        else
          sum[op][j][xx] = f[op][j][xx];
      }
  }
  long long ans = 0;
  for (int x = L[n]; x <= R2[n]; x++)
    for (int j = x; j <= n; j++) {
      ans = (ans + 1ll * C(n - x, j - x) * f[op][j][x - L[n]] % p);
    }
  cout << (ans % p + p) % p;
  return 0;
}
