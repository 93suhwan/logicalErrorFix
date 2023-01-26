#include <bits/stdc++.h>
using namespace std;
const int maxn = 4020;
const int maxm = 4020;
const int N = 2002;
const int mod = 1e9 + 7;
int n;
char s[maxn], t[maxn];
int pre[maxn][maxn], suf[maxn][maxn];
int id(char x, int y) { return (x == y + '0' || x == '?'); }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= 2 * N + 5; j++) {
        pre[i][j] = suf[i][j] = 0;
      }
    }
    pre[0][N] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = -n; j <= n; j++) {
        for (int x = 0; x < 2; x++) {
          for (int y = 0; y < 2; y++) {
            if (id(s[i], x ^ (i & 1)) && id(t[i], y ^ (i & 1))) {
              (pre[i][j + x - y + N] += pre[i - 1][j + N]) %= mod;
            }
          }
        }
      }
    }
    suf[n + 1][N] = 1;
    for (int i = n; i >= 1; i--) {
      for (int j = -n; j <= n; j++) {
        for (int x = 0; x < 2; x++) {
          for (int y = 0; y < 2; y++) {
            if (id(s[i], x ^ (i & 1)) && id(t[i], y ^ (i & 1))) {
              (suf[i][j + x - y + N] += suf[i + 1][j + N]) %= mod;
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = -n; j <= n; j++) {
        int tmp = 1;
        tmp =
            tmp * pre[i][j + N] % mod * suf[i + 1][-j + N] % mod * abs(j) % mod;
        ans = (ans + tmp) % mod;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
