#include <bits/stdc++.h>
using namespace std;
const int N = 14, MOD = 1e9 + 7;
int n;
int a[N];
int p[N][N];
int H[N][1 << N];
int d[N];
int G[4782969];
int P[1 << N];
int id_X[1 << N];
int id_Y[1 << N];
int pow_mod(int x, int n) {
  int y = 1;
  while (n) {
    if (n & 1) y = (long long)y * x % MOD;
    x = (long long)x * x % MOD;
    n >>= 1;
  }
  return y;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      p[i][j] = (long long)a[i] * pow_mod(a[i] + a[j], MOD - 2) % MOD;
  int all = (1 << n) - 1;
  for (int i = 0; i < n; i++) {
    H[i][0] = 1;
    for (int j = 0; j < n; j++) H[i][1 << j] = p[i][j];
    for (int S = 1; S <= all; S++)
      H[i][S] = (long long)H[i][(S - 1) & S] * H[i][-S & S] % MOD;
  }
  for (int S = 0; S <= all; S++)
    for (int i = 0, three = 1; i < n; i++, three *= 3)
      if (S >> i & 1) {
        id_X[S] += three;
        id_Y[S] += 2 * three;
      }
  for (int X = 0; X <= all; X++) {
    int dX = all - X;
    for (int S = dX;; S = (S - 1) & dX) {
      int Y = ~S & dX;
      if (X == 0)
        G[id_Y[Y]] = 1;
      else {
        int x = __builtin_ffs(X) - 1;
        G[id_X[X] + id_Y[Y]] =
            (long long)G[id_X[(X - 1) & X] + id_Y[Y]] * H[x][Y] % MOD;
      }
      if (S == 0) break;
    }
  }
  int ans = 0;
  for (int S = 1; S < 1 << n; S++) {
    P[S] = 1;
    for (int tS = (S - 1) & S; tS; tS = (tS - 1) & S)
      P[S] = (P[S] - (long long)P[tS] * G[id_X[tS] + id_Y[S & ~tS]]) % MOD;
    ans = (ans + (long long)P[S] * G[id_X[S] + id_Y[all & ~S]] % MOD *
                     __builtin_popcount(S)) %
          MOD;
  }
  cout << (ans + MOD) % MOD << endl;
}
