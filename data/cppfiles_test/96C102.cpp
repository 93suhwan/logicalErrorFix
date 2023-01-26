#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int cases = -1;
void getCases() {
  int SingleCase = 1;
  if (SingleCase == 1) {
    cases = 1;
  } else if (SingleCase == 0) {
    scanf("%d", &cases);
  } else {
    assert(false && "fix the function");
  }
}
int n, x;
void Input() { scanf("%d%d", &n, &x); }
const int N = 505;
const int MOD = 998244353;
LL c[N][N];
LL dp[N][N];
LL add(LL a, LL b) { return (a + b) % MOD; }
LL mul(LL a, LL b) { return (a * b) % MOD; }
int main() {
  getCases();
  while (cases--) {
    Input();
    for (int i = 0; i <= n; ++i) {
      c[i][0] = c[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
      }
    }
    dp[n][0] = 1;
    for (int i = n; i > 1; i--) {
      for (int j = 0; j < x; ++j) {
        if (!dp[i][j]) continue;
        LL pw = 1;
        LL nj = min(x, j + (i - 1));
        for (int k = i; k >= 0; k--) {
          dp[k][nj] = add(dp[k][nj], mul(dp[i][j], mul(c[i][k], pw)));
          pw = mul(pw, nj - j);
        }
      }
    }
    LL ans = 0;
    for (int i = 0; i <= x; ++i) ans = add(ans, dp[0][i]);
    printf("%lld\n", ans);
  }
}
