#include <bits/stdc++.h>
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
const int MAXN = 6011;
int N;
struct Pos {
  int x, y;
} P[MAXN];
int Cnt[MAXN][4][4][4];
int Norm(int a) { return (a % 4 + 4) & 3; }
int Size(int x1, int y1, int x2, int y2) { return x1 * y2 - y1 * x2 + 256; }
int C2(int a) { return a * (a - 1); }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  for (int i = 1; i < N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      int g = gcd(abs(P[i].x - P[j].x), abs(P[i].y - P[j].y));
      ++Cnt[i][Norm(P[i].x - P[j].x)][Norm(P[i].y - P[j].y)][g & 3];
      ++Cnt[j][Norm(P[j].x - P[i].x)][Norm(P[j].y - P[i].y)][g & 3];
    }
  }
  long long EEE = 0, OOE = 0;
  for (int i = 1; i <= N; ++i) {
    for (int x1 = 0; x1 < 4; ++x1) {
      for (int y1 = 0; y1 < 4; ++y1) {
        for (int b1 = 0; b1 < 4; ++b1) {
          if (b1 & 1) {
            if ((Size(x1, y1, x1, y1) & 3) == ((b1 << 1) & 3))
              OOE += C2(Cnt[i][x1][y1][b1]);
            if ((Size(x1, y1, x1, y1) & 3) == ((b1 + (b1 ^ 2)) & 3))
              OOE += Cnt[i][x1][y1][b1] * Cnt[i][x1][y1][b1 ^ 2];
          } else {
            if ((Size(x1, y1, x1, y1) & 3) == ((b1 << 1) & 3))
              EEE += C2(Cnt[i][x1][y1][b1]);
            if ((Size(x1, y1, x1, y1) & 3) == ((b1 + (b1 ^ 2)) & 3))
              EEE += Cnt[i][x1][y1][b1] * Cnt[i][x1][y1][b1 ^ 2];
          }
          if (b1 & 1) {
            if ((Size(x1, y1, x1 ^ 2, y1) & 3) == (((b1 << 1) + 2) & 3))
              OOE += Cnt[i][x1][y1][b1] * Cnt[i][x1 ^ 2][y1][b1];
            if ((Size(x1, y1, x1 ^ 2, y1) & 3) == ((b1 + (b1 ^ 2) + 2) & 3))
              OOE += Cnt[i][x1][y1][b1] * Cnt[i][x1 ^ 2][y1][b1 ^ 2];
          } else {
            if ((Size(x1, y1, x1 ^ 2, y1) & 3) == (((b1 << 1) + 2) & 3))
              EEE += Cnt[i][x1][y1][b1] * Cnt[i][x1 ^ 2][y1][b1];
            if ((Size(x1, y1, x1 ^ 2, y1) & 3) == ((b1 + (b1 ^ 2) + 2) & 3))
              EEE += Cnt[i][x1][y1][b1] * Cnt[i][x1 ^ 2][y1][b1 ^ 2];
          }
          if (b1 & 1) {
            if ((Size(x1, y1, x1, y1 ^ 2) & 3) == (((b1 << 1) + 2) & 3))
              OOE += Cnt[i][x1][y1][b1] * Cnt[i][x1][y1 ^ 2][b1];
            if ((Size(x1, y1, x1, y1 ^ 2) & 3) == ((b1 + (b1 ^ 2) + 2) & 3))
              OOE += Cnt[i][x1][y1][b1] * Cnt[i][x1][y1 ^ 2][b1 ^ 2];
          } else {
            if ((Size(x1, y1, x1, y1 ^ 2) & 3) == (((b1 << 1) + 2) & 3))
              EEE += Cnt[i][x1][y1][b1] * Cnt[i][x1][y1 ^ 2][b1];
            if ((Size(x1, y1, x1, y1 ^ 2) & 3) == ((b1 + (b1 ^ 2) + 2) & 3))
              EEE += Cnt[i][x1][y1][b1] * Cnt[i][x1][y1 ^ 2][b1 ^ 2];
          }
          if (b1 & 1) {
            if ((Size(x1, y1, x1 ^ 2, y1 ^ 2) & 3) == (((b1 << 1) + 2) & 3))
              OOE += Cnt[i][x1][y1][b1] * Cnt[i][x1 ^ 2][y1 ^ 2][b1];
            if ((Size(x1, y1, x1 ^ 2, y1 ^ 2) & 3) == ((b1 + (b1 ^ 2) + 2) & 3))
              OOE += Cnt[i][x1][y1][b1] * Cnt[i][x1 ^ 2][y1 ^ 2][b1 ^ 2];
          } else {
            if ((Size(x1, y1, x1 ^ 2, y1 ^ 2) & 3) == (((b1 << 1) + 2) & 3))
              EEE += Cnt[i][x1][y1][b1] * Cnt[i][x1 ^ 2][y1 ^ 2][b1];
            if ((Size(x1, y1, x1 ^ 2, y1 ^ 2) & 3) == ((b1 + (b1 ^ 2) + 2) & 3))
              EEE += Cnt[i][x1][y1][b1] * Cnt[i][x1 ^ 2][y1 ^ 2][b1 ^ 2];
          }
        }
      }
    }
  }
  EEE /= 6;
  OOE /= 2;
  printf("%lld\n", EEE + OOE);
  return 0;
}
