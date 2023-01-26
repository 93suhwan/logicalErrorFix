#include <bits/stdc++.h>
using namespace std;
const int N = 6100;
int C[4][4][4], X[N], Y[N], S, n, m, i, j, X1, x2, Y1, y2, b1, b2, b3, t;
long long eee, eoo;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int S2(int x1, int y1, int x2, int y2, int x3, int y3) {
  int res = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
  res %= 4;
  if (res < 0) res += 4;
  return res;
}
int main() {
  for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d%d", X + i, Y + i);
  for (i = 1; i <= n; ++i) {
    for (memset(C, 0, sizeof(C)), j = 1; j <= n; ++j)
      if (i != j)
        C[X[j] % 4][Y[j] % 4][gcd(abs(X[i] - X[j]), abs(Y[i] - Y[j])) % 4]++;
    for (X1 = 0; X1 < 4; ++X1)
      for (Y1 = 0; Y1 < 4; ++Y1)
        for (b1 = 0; b1 < 4; ++b1) {
          for (t = C[X1][Y1][b1]--, x2 = X1 & 1; x2 < 4; x2 += 2)
            for (y2 = Y1 & 1; y2 < 4; y2 += 2)
              for (b2 = b1 & 1; b2 < 4; b2 += 2) {
                S = S2(X[i], Y[i], X1, Y1, x2, y2);
                S >>= 1;
                b3 = gcd(abs(X1 - x2), abs(Y1 - y2));
                if ((S - (b1 + b2 + b3) / 2 + 1) & 1) {
                  if (b1 & 1)
                    eoo += t * C[x2][y2][b2];
                  else
                    eee += t * C[x2][y2][b2];
                }
              }
          C[X1][Y1][b1]++;
        }
  }
  printf("%lld\n", eee / 6 + eoo / 2);
}
