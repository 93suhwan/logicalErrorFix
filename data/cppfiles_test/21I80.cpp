#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, s, P;
int f[N][N][N], C[N][N], fac[N], mx[N][N];
void add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m >> s >> P;
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
  }
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % P;
  for (int i = 0; i <= n; i++) {
    for (int k = i + 1; k <= n; k++) f[i][0][k] = fac[i];
    f[i][0][0] = fac[i];
    for (int j = 0; j <= i; j++) {
      for (int k = 1; k <= i; k++) {
        for (int a = 1; a <= i; a++) {
          int o = j - (k == 1);
          for (int x = max(0, o - mx[i - a][k - 1]);
               x <= min(o, mx[a - 1][k - 1]); x++) {
            add(f[i][j][k], 1ll * f[a - 1][x][k - 1] * f[i - a][o - x][k - 1] %
                                P * C[i - 1][a - 1] % P);
          }
        }
        if (f[i][j][k]) mx[i][k] = j;
      }
    }
  }
  cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  cout << f[n][s][m] << endl;
  return 0;
}
