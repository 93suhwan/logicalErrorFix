#include <bits/stdc++.h>
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];
  long long eee = 0, eoo = 0;
  for (int i = 0; i < n; ++i) {
    int cnt[4][4][4] = {};
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        ++cnt[x[j] % 4][y[j] % 4][gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) % 4];
      }
    }
    int x0 = x[i] % 4;
    int y0 = y[i] % 4;
    for (int x1 = 0; x1 < 4; ++x1) {
      for (int y1 = 0; y1 < 4; ++y1) {
        for (int b1 = 0; b1 < 4; ++b1) {
          int c1 = cnt[x1][y1][b1];
          if (!c1) continue;
          --cnt[x1][y1][b1];
          for (int x2 = x1 % 2; x2 < 4; x2 += 2) {
            for (int y2 = y1 % 2; y2 < 4; y2 += 2) {
              for (int b2 = b1 % 2; b2 < 4; b2 += 2) {
                int c2 = cnt[x2][y2][b2];
                if (!c2) continue;
                int s = x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1);
                s = (s % 4 + 4) % 4;
                if (s % 2) continue;
                int b3 = gcd(x1 - x2, y1 - y2);
                int a = s / 2 - (b1 + b2 + b3) / 2 + 1;
                if (a % 2) {
                  if (b1 % 2 == 1)
                    eoo += 1ll * c1 * c2;
                  else
                    eee += 1ll * c1 * c2;
                }
              }
            }
          }
          ++cnt[x1][y1][b1];
        }
      }
    }
  }
  eee /= 6;
  eoo /= 2;
  std::cout << (eee + eoo) << '\n';
  return 0;
}
