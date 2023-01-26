#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
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
template <typename T>
void r1(T &x) {
  x = 0;
  char c(getchar());
  int f(1);
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = (x * 10) + (c ^ 48);
  x *= f;
}
const int mod = 998244353;
template <typename T, typename... Args>
inline void r1(T &t, Args &...args) {
  r1(t);
  r1(args...);
}
const int maxn = 1e5 + 5;
int n, a[maxn], s[maxn], tot(0);
int f[2][maxn];
int inc(int x, int y) { return x += y - mod, x + ((x >> 31) & mod); }
void add(int &x, int y) { x = inc(x, y); }
int Mod(int x) { return x -= mod, x + ((x >> 31) & mod); }
signed main() {
  int i, j;
  r1(n);
  for (i = 1; i <= n; ++i) r1(a[i]);
  for (i = 1; i <= n; i += a[i]) {
    s[++tot] = (a[i] > 1);
    for (j = i; j <= i + a[i] - 1; ++j)
      if (a[i] != a[j]) return puts("0"), 0;
  }
  f[s[1]][0] = 1;
  for (i = 1; i < tot; ++i) {
    if (s[i + 1]) {
      for (j = i - 1; j >= 0; --j) {
        add(f[1][j + 1], Mod(f[1][j] << 1));
        add(f[1][j + 1], f[0][j]);
        add(f[1][j], f[0][j]);
        f[0][j] = 0;
      }
    } else {
      for (j = i - 1; j >= 0; --j) {
        add(f[0][j + 1], Mod(f[1][j] << 1));
        add(f[0][j + 1], f[0][j]);
        add(f[1][j], f[0][j]);
        f[0][j] = 0;
      }
    }
  }
  long long ans(0), fac(1);
  for (i = 1; i <= tot; ++i) {
    fac = fac * i % mod;
    long long tmp = (f[0][i - 1] + 2ll * f[1][i - 1]) % mod * fac % mod;
    if ((tot - i) & 1)
      ans = Mod(ans - tmp + mod);
    else
      ans = Mod(ans + tmp);
  }
  printf("%lld\n", ans);
  return 0;
}
