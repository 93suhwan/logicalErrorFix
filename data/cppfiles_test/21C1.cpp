#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmin(T &first, T second) {
  return second < first ? first = second, 1 : 0;
}
template <typename T>
bool chkmax(T &first, T second) {
  return first < second ? first = second, 1 : 0;
}
template <typename T>
void readint(T &first) {
  first = 0;
  int f = 1;
  char c;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) first = first * 10 + (c - '0');
  first *= f;
}
int MOD;
inline int dmy(int first) { return first >= MOD ? first - MOD : first; }
inline void inc(int &first, int second) { first = dmy(first + second); }
int qmi(int first, int second) {
  int ans = 1;
  for (; second; second >>= 1, first = 1ll * first * first % MOD)
    if (second & 1) ans = 1ll * ans * first % MOD;
  return ans;
}
const int MAXN = 105;
int n, m, k, c[MAXN][MAXN], f[MAXN][MAXN][MAXN];
int main() {
  cin >> n >> m >> k >> MOD;
  f[1][0][0] = f[1][1][1] = 1;
  for (int i = 2; i <= n; ++i) f[1][i][1] = 1ll * f[1][i - 1][1] * i % MOD;
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) c[i][j] = dmy(c[i - 1][j - 1] + c[i - 1][j]);
  }
  for (int second = 2; second <= m; ++second) {
    f[second][0][0] = 1;
    for (int first = 1; first < second; ++first)
      f[second][first][0] = f[1][first][1];
    for (int first = second; first <= n; ++first) {
      for (int z = 0; z <= k; ++z)
        for (int i = 1; i <= first; ++i) {
          int t = 0;
          for (int j = 0; j <= z; ++j)
            inc(t, 1ll * f[second - 1][i - 1][j] *
                       f[second - 1][first - i][z - j] % MOD);
          inc(f[second][first][z], 1ll * t * c[first - 1][i - 1] % MOD);
        }
      if (1.0 * clock() / CLOCKS_PER_SEC > 0.96) return 0 * printf("0\n");
    }
  }
  printf("%d\n", f[m][n][k]);
  return 0;
}
