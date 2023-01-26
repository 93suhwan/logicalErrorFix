#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long M = 1e9 + 7;
const long long MM = 998244353;
long long modpow(long long a, long long b, long long mod) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    res %= mod;
    a = a * a;
    a %= mod;
  }
  return res;
}
long long power(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
void solve() {
  long long W, H;
  cin >> W >> H;
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long w, h;
  cin >> w >> h;
  long long dist1 = 0;
  long long dist2 = 0;
  long long dist3 = 0;
  long long dist4 = 0;
  if (W - (x2 - x1) >= w)
    dist1 =
        (((long long)0 > (long long)w - x1) ? (long long)0 : (long long)w - x1);
  else
    dist1 = INF;
  if (H - (y2 - y1) >= h)
    dist2 =
        (((long long)0 > (long long)h - y1) ? (long long)0 : (long long)h - y1);
  else
    dist2 = INF;
  if (W - (x2 - x1) >= w)
    dist3 =
        (((long long)0 > (long long)w - (W - x2)) ? (long long)0
                                                  : (long long)w - (W - x2));
  else
    dist3 = INF;
  if (H - (y2 - y1) >= h)
    dist4 =
        (((long long)0 > (long long)h - (H - y2)) ? (long long)0
                                                  : (long long)h - (H - y2));
  else
    dist4 = INF;
  if (dist1 == INF && dist2 == INF)
    cout << -1 << "\n";
  else {
    double dist =
        (((long long)dist1 <
          (long long)(((long long)dist2 <
                       (long long)(((long long)dist3 < (long long)dist4)
                                       ? (long long)dist3
                                       : (long long)dist4))
                          ? (long long)dist2
                          : (long long)(((long long)dist3 < (long long)dist4)
                                            ? (long long)dist3
                                            : (long long)dist4)))
             ? (long long)dist1
             : (long long)(((long long)dist2 <
                            (long long)(((long long)dist3 < (long long)dist4)
                                            ? (long long)dist3
                                            : (long long)dist4))
                               ? (long long)dist2
                               : (long long)(((long long)dist3 <
                                              (long long)dist4)
                                                 ? (long long)dist3
                                                 : (long long)dist4))) *
        1.0;
    double d = 122.345;
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    cout << dist << "\n";
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
