#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 1000000005;
const int64_t INF = 1000000000000000000;
const int N = 2e5 + 7;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t n, z, f, w, b;
  cin >> n;
  vector<std::pair<int64_t, int64_t> > a(n);
  for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  int64_t R = 0, o = 0, e = 0;
  int A[4][4][4];
  for (int i = 0; i < n; ++i) {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k) A[i][j][k] = 0;
    for (int j = 0; j < n; ++j)
      if (i != j) {
        A[a[j].first % 4][a[j].second % 4]
         [gcd(abs(a[j].first - a[i].first), abs(a[j].second - a[i].second)) %
          4]++;
      }
    for (int x0 = 0; x0 < 4; ++x0)
      for (int y0 = 0; y0 < 4; ++y0)
        for (int x1 = 0; x1 < 4; ++x1)
          for (int y1 = 0; y1 < 4; ++y1)
            for (int m0 = 0; m0 < 4; ++m0)
              for (int m1 = 0; m1 < 4; ++m1)
                if (A[x0][y0][m0] != 0 && A[x1][y1][m1] != 0) {
                  if (x0 % 2 != x1 % 2 || y0 % 2 != y1 % 2) continue;
                  if (x0 == x1 && y0 == y1) {
                    b = 0;
                    if (m0 == m1)
                      w = (A[x0][y0][m0] * (A[x0][y0][m0] - 1));
                    else
                      w = A[x0][y0][m0] * A[x1][y1][m1];
                  } else {
                    b = 2;
                    w = A[x0][y0][m0] * A[x1][y1][m1];
                  }
                  b = (b + m0 + m1) % 4;
                  z = abs((x0 - a[i].first) * (y1 - a[i].second) -
                          (x1 - a[i].first) * (y0 - a[i].second)) %
                      4;
                  if (z % 2 == 0 && b == z) {
                    if (m0 % 2 && m1 % 2)
                      o += w;
                    else
                      e += w;
                  }
                }
  }
  cout << (e / 3 + o) / 2;
}
