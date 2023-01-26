#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
void solve() {
  long long int n, i, W, H;
  cin >> W >> H;
  long long int x1, x2, y2, y1;
  cin >> x1 >> y1 >> x2 >> y2;
  long long int w, h;
  cin >> w >> h;
  if (W - (x2 - x1) < w && H - (y2 - y1) < h) {
    cout << "-1" << endl;
    return;
  }
  if (w > W || h > H) {
    cout << "-1" << endl;
    return;
  }
  long long int wt = max((long long int)0, w - max(x1, W - x2));
  if (wt > min(x1, W - x2)) {
    wt = LLONG_MAX;
  }
  long long int ht = max((long long int)0, h - max(y1, H - y2));
  if (ht > min(y1, H - y2)) {
    ht = LLONG_MAX;
  }
  long long int ans = min(wt, ht);
  if (ans == LLONG_MAX) {
    ans = -1;
  }
  cout << ans;
  cout << endl;
}
