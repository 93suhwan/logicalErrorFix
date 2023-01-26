#include <bits/stdc++.h>
using namespace std;
const long long inf = long long(1e9) + 7;
long long cnt[4][4];
long long C(long long n, long long k) {
  if (n < k) return 0;
  if (k == 2) return n * (n - 1) / 2;
  if (k == 3) return n * (n - 1) * (n - 2) / 6;
}
int main() {
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    cnt[x % 4][y % 4]++;
  }
  long long ans = 0;
  for (int x1 = 0; x1 < 4; x1 += 2)
    for (int x2 = x1; x2 < 4; x2 += 2)
      for (int x3 = x2; x3 < 4; x3 += 2)
        for (int y1 = 0; y1 < 4; y1 += 2)
          for (int y2 = 0; y2 < 4; y2 += 2)
            for (int y3 = 0; y3 < 4; y3 += 2) {
              long long c1 = cnt[x1][y1];
              long long c2 = cnt[x2][y2];
              long long c3 = cnt[x3][y3];
              bool z1 = ((x1 == x2) && (y1 == y2));
              bool z2 = ((x1 == x3) && (y1 == y2));
              bool z3 = ((x2 == x3) && (y2 == y3));
              if (z1 && z2 && z3) {
                ans = ans + C(c1, 3);
              } else if (z1 && !z2 && !z3) {
                ans = ans + C(c1, 2) * c3;
              } else if (!z1 && z2 && !z3) {
                ans = ans + C(c1, 2) * c2;
              } else if (!z1 && !z2 && z3) {
                ans = ans + C(c2, 2) * c1;
              }
            }
  cout << ans << endl;
  return 0;
}
