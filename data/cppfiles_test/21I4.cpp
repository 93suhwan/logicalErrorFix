#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int N = 110;
int p;
int f[N][N][N], C[N][N], fac[N], mx[N][N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  int n, m, k;
  cin >> n >> m >> k >> p;
  C[0][0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= 100; i++) {
    C[i][0] = 1;
    fac[i] = 1LL * fac[i - 1] * i % p;
    for (int j = 1; j <= 100; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
  }
  for (int good = 1; good <= m; good++) {
    f[0][0][good] = 1;
    mx[0][good] = 0;
  }
  for (int l = 1; l <= n; l++) {
    for (int good = 1; good <= m; good++) {
      for (int num = 0; num <= k && num <= l; num++) {
        if (good == 1) {
          if (num != 1)
            f[l][num][good] = 0;
          else
            f[l][num][good] = fac[l], mx[l][good] = max(mx[l][good], num);
          continue;
        } else
          for (int ps = 1; ps <= l; ps++) {
            int res = 0, bg = 0, ed;
            ed = mx[ps - 1][good - 1];
            bg = num - mx[l - ps][good - 1];
            bg = max(bg, 0);
            for (int numl = bg; numl <= ed; numl++) {
              res = (1LL * f[ps - 1][numl][good - 1] *
                         f[l - ps][num - numl][good - 1] +
                     res) %
                    p;
            }
            res = 1LL * res * C[l - 1][ps - 1] % p;
            f[l][num][good] = (f[l][num][good] + res) % p;
          }
        if (f[l][num][good]) mx[l][good] = max(mx[l][good], num);
      }
    }
  }
  cout << f[n][k][m] << '\n';
}
