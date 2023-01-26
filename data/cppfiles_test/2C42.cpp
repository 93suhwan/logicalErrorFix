#include <bits/stdc++.h>
using namespace std;
int read() {
  int w = 0, flg = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      flg = -1;
    }
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    w = w * 10 + ch - '0', ch = getchar();
  }
  return w * flg;
}
int Sum(int a, int b, int c, int d, int e, int f) {
  int ret = b * c + d * e + a * f - a * d - b * e - c * f;
  return (ret % 4 + 4) % 4;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n, x[6010], y[6010], cnt[4][4][4];
long long re1, re2;
int main() {
  n = read();
  for (int i = (1); i <= (n); i++) x[i] = read(), y[i] = read();
  for (int i = (1); i <= (n); i++) {
    memset(cnt, 0, sizeof(cnt));
    for (int j = (1); j <= (n); j++) {
      if (i == j) continue;
      cnt[x[j] % 4][y[j] % 4][gcd(abs(x[j] - x[i]), abs(y[j] - y[i])) % 4]++;
    }
    for (int x1 = (0); x1 <= (3); x1++) {
      for (int y1 = (0); y1 <= (3); y1++) {
        for (int g1 = (0); g1 <= (3); g1++) {
          long long p1 = cnt[x1][y1][g1];
          cnt[x1][y1][g1]--;
          for (int x2 = (x1 & 1); x2 < 4; x2 += 2) {
            for (int y2 = (y1 & 1); y2 < 4; y2 += 2) {
              for (int g2 = (g1 & 1); g2 < 4; g2 += 2) {
                long long p2 = cnt[x2][y2][g2];
                int S = Sum(x[i], y[i], x1, y1, x2, y2);
                if (S & 1) break;
                S >>= 1;
                int g3 = gcd(abs(x2 - x1), abs(y2 - y1));
                if ((S - (g1 + g2 + g3) / 2 + 1) & 1) {
                  if (g1 & 1)
                    re1 += p1 * p2;
                  else
                    re2 += p1 * p2;
                }
              }
            }
          }
          cnt[x1][y1][g1]++;
        }
      }
    }
  }
  printf("%lld\n", re1 / 2 + re2 / 6);
  return 0;
}
