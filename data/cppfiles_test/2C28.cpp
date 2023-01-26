#include <bits/stdc++.h>
using namespace std;
const int MX = 6000;
int double_area(int x1, int y1, int x2, int y2, int x3, int y3) {
  int tmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
  tmp = abs(tmp);
  return tmp % 4;
}
int gcd(int a, int b) {
  while (b) {
    int c = a % b;
    a = b;
    b = c;
  }
  return a;
}
pair<int, int> pts[MX];
int g[MX][MX];
int cnt[4][4][4];
int main() {
  int n;
  ignore = scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    ignore = scanf("%d %d", &x, &y);
    pts[i] = {x, y};
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      g[i][j] = g[j][i] = gcd(abs(pts[i].first - pts[j].first),
                              abs(pts[i].second - pts[j].second)) %
                          4;
    }
  }
  long long ans_2 = 0, ans_6 = 0;
  for (int pivot = 0; pivot < n; pivot++) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
      if (i == pivot) continue;
      cnt[pts[i].first % 4][pts[i].second % 4][g[i][pivot]]++;
    }
    for (int x1 = 0; x1 < 4; x1++)
      for (int y1 = 0; y1 < 4; y1++)
        for (int g1 = 0; g1 < 4; g1++)
          for (int x2 = 0; x2 < 4; x2++)
            for (int y2 = 0; y2 < 4; y2++)
              for (int g2 = 0; g2 < 4; g2++) {
                int g3 = gcd(abs(x1 - x2), abs(y1 - y2));
                if (g3 != 0 && g3 != 2) continue;
                int B = (g1 + g2 + g3) % 4;
                int S = double_area(x1, y1, x2, y2, pts[pivot].first,
                                    pts[pivot].second);
                if (S % 2 != 0) continue;
                if (S % 4 != B) continue;
                long long tmp;
                if (x1 == x2 && y1 == y2 && g1 == g2) {
                  tmp = cnt[x1][y1][g1] * (cnt[x1][y1][g1] - 1);
                } else {
                  tmp = cnt[x1][y1][g1] * cnt[x2][y2][g2];
                }
                if (g1 % 2 == 1) {
                  ans_2 += tmp;
                } else {
                  ans_6 += tmp;
                }
              }
  }
  ans_2 /= 2;
  ans_6 /= 6;
  printf("%lld\n", ans_2 + ans_6);
}
