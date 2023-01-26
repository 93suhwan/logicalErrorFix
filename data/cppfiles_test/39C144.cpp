#include <bits/stdc++.h>
using namespace std;
void solve(int tc = 0) {
  int W, H;
  cin >> W >> H;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int w, h;
  cin >> w >> h;
  int ans = 1e8;
  if (w + (x2 - x1) <= W) {
    ans = min(ans, max(0, w - x1));
    ans = min(ans, max(0, x2 - (W - w)));
  }
  if (h + (y2 - y1) <= H) {
    ans = min(ans, max(0, h - y1));
    ans = min(ans, max(0, y2 - (H - h)));
  }
  cout << (ans == 1e8 ? -1 : ans) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}
