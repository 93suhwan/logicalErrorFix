#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const int MAXM = 1e9 + 7;
const long long int MOD = 1e15 + 7;
const int inf = MAXM;
long long int abso(long long int a) {
  if (a > 0) return a;
  return -1 * a;
}
void solve() {
  long long int W, H, x1, x2, y1, y2, w, h;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  if (x1 >= w or y1 >= h) {
    cout << "0";
    return;
  }
  if (x2 + (w - x1) <= W and y2 + (h - y1) <= H) {
    cout << min((w - x1), (h - y1));
  } else if (x2 + (w - x1) <= W) {
    cout << w - x1;
  } else if (y2 + (h - y1) <= H) {
    cout << h - y1;
  } else {
    cout << -1;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
