#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
const long long Mod = 1000000007, Mod2 = 998244353;
const long long MOD = Mod2;
const long long maxn = 105;
long long n, m, k, p;
long long dp[maxn][maxn][maxn], fac[maxn], C[maxn][maxn];
void orzck() {
  long double start = clock();
  cin >> n >> m >> k >> p;
  if (m + k > n + 1) {
    print(0);
    return;
  }
  fac[0] = 1;
  for (long long i = (1); i < ((long long)(maxn)); i++)
    fac[i] = fac[i - 1] * i % p;
  C[0][0] = 1;
  for (long long i = (1); i < ((long long)(n + 2)); i++)
    for (long long j = (0); j < ((long long)(i + 1)); j++) {
      if (j) C[i][j] += C[i - 1][j - 1];
      C[i][j] += C[i - 1][j];
      C[i][j] %= p;
    }
  for (long long j = (0); j < ((long long)(m + 1)); j++) dp[0][j][0] = 1;
  for (long long i = (1); i < ((long long)(n + 1)); i++)
    for (long long j = (1); j < ((long long)(m + 1)); j++)
      for (long long cnt = (0); cnt < ((long long)(k + 1)); cnt++) {
        if (j == 1) {
          if (cnt == 1)
            dp[i][j][cnt] = fac[i];
          else
            dp[i][j][cnt] = 0;
          continue;
        }
        for (long long pos = (0); pos < ((long long)(i)); pos++) {
          if (pos > i - 1 - pos) break;
          long long times = 1 + (pos != i - 1 - pos);
          long long tmp = 0;
          for (long long cntl = (0); cntl < ((long long)(cnt + 1)); cntl++)
            tmp +=
                (dp[pos][j - 1][cntl] * dp[i - 1 - pos][j - 1][cnt - cntl] % p);
          tmp %= p;
          tmp *= times * C[i - 1][pos] % p;
          tmp %= p;
          dp[i][j][cnt] += tmp;
        }
        dp[i][j][cnt] %= p;
      }
  print(dp[n][m][k]);
  826;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(15);
  long long t;
  t = 1;
  while (t--) orzck();
  return 0;
}
