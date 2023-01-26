#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 0x3F3F3F3F3F3F3F3F;
bool findInter(long long p1, long long q1, long long p2, long long q2,
               long long x1, long long y1, long long x2, long long y2) {
  long long x5 = max(p1, x1);
  long long y5 = max(q1, y1);
  long long x6 = min(p2, x2);
  long long y6 = min(q2, y2);
  if (x5 > x6 || y5 > y6) {
    return false;
  }
  return true;
}
bool inside(long long x1, long long y1, long long x2, long long y2, long long W,
            long long H) {
  if (x1 >= 0 && x1 <= W && y1 >= 0 && y1 <= H)
    return x2 >= 0 && x2 <= W && y2 >= 0 && y2 <= H;
  return false;
}
void minimize(long long p1, long long q1, long long p2, long long q2,
              long long x1, long long y1, long long x2, long long y2,
              long long &ans, long long W, long long H) {
  if (x1 <= p2 && inside(p2, y1, p2 + x2 - x1, y2, W, H))
    ans = min(ans, p2 - x1);
  if (y1 <= q2 && inside(x1, q2, x2, q2 + y2 - y1, W, H))
    ans = min(ans, q2 - y1);
  if (x2 >= p1 && inside(p1 - (x2 - x1), y1, p1, y2, W, H))
    ans = min(ans, x2 - p1);
  if (y2 >= q1 && inside(x1, q1 - (y2 - y1), x2, q1, W, H))
    ans = min(ans, y2 - q1);
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long W, H;
    long long x1, y1, x2, y2;
    long long w, h;
    cin >> W >> H >> x1 >> y1;
    cin >> x2 >> y2 >> w >> h;
    long long ans = INF;
    long long p1, q1, p2, q2;
    p1 = q1 = 0;
    p2 = p1 + w, q2 = q1 + h;
    if (!findInter(p1, q1, p2, q2, x1, y1, x2, y2))
      ans = 0;
    else
      minimize(p1, q1, p2, q2, x1, y1, x2, y2, ans, W, H);
    p1 = W - w, q1 = 0;
    p2 = p1 + w, q2 = q1 + h;
    if (!findInter(p1, q1, p2, q2, x1, y1, x2, y2))
      ans = 0;
    else
      minimize(p1, q1, p2, q2, x1, y1, x2, y2, ans, W, H);
    p1 = 0, q1 = H - h;
    p2 = p1 + w, q2 = q1 + h;
    if (!findInter(p1, q1, p2, q2, x1, y1, x2, y2))
      ans = 0;
    else
      minimize(p1, q1, p2, q2, x1, y1, x2, y2, ans, W, H);
    p1 = W - w, q1 = H - h;
    p2 = p1 + w, q2 = q1 + h;
    if (!findInter(p1, q1, p2, q2, x1, y1, x2, y2))
      ans = 0;
    else
      minimize(p1, q1, p2, q2, x1, y1, x2, y2, ans, W, H);
    if (ans == INF) ans = -1;
    cout << ans << "\n";
  }
}
