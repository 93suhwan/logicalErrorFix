#include <bits/stdc++.h>
using namespace std;
using gg = long long;
constexpr gg MAX = 405;
constexpr gg mod = 1e9 + 7;
constexpr gg INF = 4e16;
constexpr double eps = 1e-12;
gg ti, ni, mi, ki, di, pi, xi, yi;
gg up(gg n, gg m) { return n >= 0 ? (n + m - 1) / m : n / m; }
gg down(gg n, gg m) { return n >= 0 ? n / m : (n - m + 1) / m; }
gg a[MAX][MAX], preSum[MAX][MAX], r[MAX][MAX], c[MAX][MAX];
gg pv[MAX];
void getPrefixSum(gg m, gg n) {
  for (gg i = 1; i <= m; ++i) {
    for (gg j = 1; j <= n; ++j) {
      preSum[i][j] =
          preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + a[i][j];
    }
  }
}
gg getSum(gg r1, gg c1, gg r2, gg c2) {
  return preSum[r2][c2] - preSum[r1 - 1][c2] - preSum[r2][c1 - 1] +
         preSum[r1 - 1][c1 - 1];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ti = 1;
  cin >> ti;
  while (ti--) {
    cin >> mi >> ni;
    string s;
    for (gg i = (0); i <= (mi); i += (1)) {
      for (gg j = (0); j <= (ni); j += (1)) {
        preSum[i][j] = r[i][j] = c[i][j] = 0;
      }
    }
    for (gg i = (1); i <= (mi); i += (1)) {
      cin >> s;
      for (gg j = (1); j <= (ni); j += (1)) {
        a[i][j] = s[j - 1] - '0';
        r[i][j] = r[i][j - 1] + 1 - a[i][j];
        c[i][j] = c[i - 1][j] + 1 - a[i][j];
      }
    }
    getPrefixSum(mi, ni);
    gg ans = INF;
    for (gg x1 = (1); x1 <= (mi); x1 += (1)) {
      for (gg x2 = (x1 + 4); x2 <= (mi); x2 += (1)) {
        pv[2] = c[x2 - 1][1] - c[x1][1] + c[x2 - 1][2] - c[x1][1];
        for (gg y = (3); y <= (ni); y += (1)) {
          pv[y] = getSum(x1 + 1, 2, x2 - 1, y - 1) + r[x1][y - 1] - r[x1][1] +
                  r[x2][y - 1] - r[x2][1] + c[x2 - 1][1] - c[x1][1] +
                  c[x2 - 1][y] - c[x1][y];
        }
        gg m = INF;
        for (gg y = (ni); y >= (5); y -= (1)) {
          m = min(pv[y], m);
          gg ty = y - 3;
          ans = min(ans, m - pv[ty] + x2 - x1 + 1 - a[x1][ty] - a[x2][ty]);
        }
        ans = min({ans, m, pv[4]});
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
