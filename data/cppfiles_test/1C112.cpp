#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6002;
struct point {
  int x, y;
};
int n;
vector<point> v;
long long cntp[8][8];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x %= 4;
    y %= 4;
    cntp[x][y]++;
    v.push_back({x, y});
  }
  long long cnt = 0;
  for (int x1 = 0; x1 < 4; x1 += 2) {
    for (int y1 = 0; y1 < 4; y1 += 2) {
      for (int x2 = 0; x2 < 4; x2 += 2) {
        for (int y2 = 0; y2 < 4; y2 += 2) {
          for (int x3 = 0; x3 < 4; x3 += 2) {
            for (int y3 = 0; y3 < 4; y3 += 2) {
              if (x1 * 4 + y1 > x2 * 4 + y2) continue;
              if (x2 * 4 + y2 > x3 * 4 + y3) continue;
              int cnt1 = 0;
              if (x1 == x2 && y1 == y2) cnt1++;
              if (x1 == x3 && y1 == y3) cnt1++;
              if (x2 == x3 && y2 == y3) cnt1++;
              if (cnt1 == 1) {
                if (x1 == x2 && y1 == y2)
                  cnt += (cntp[x1][y1] * (cntp[x2][y2] - 1ll) * cntp[x3][y3]) /
                         2ll;
                else if (x1 == x3 && y1 == y3)
                  cnt += ((cntp[x1][y1] - 1ll) * cntp[x2][y2] * cntp[x3][y3]) /
                         2ll;
                else if (x3 == x2 && y3 == y2)
                  cnt += (cntp[x1][y1] * (cntp[x2][y2] - 1ll) * cntp[x3][y3]) /
                         2ll;
              } else if (cnt1 == 3)
                cnt += (cntp[x1][y1] * (cntp[x2][y2] - 1ll) *
                        (cntp[x3][y3] - 2ll)) /
                       6ll;
            }
          }
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
