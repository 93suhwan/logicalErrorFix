#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long W, H;
  cin >> W >> H;
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long height = y2 - y1;
  long long width = x2 - x1;
  long long w, h;
  cin >> w >> h;
  double ans = 1e9;
  if (h > y1) {
    if (height + h <= H) {
      ans = min((double)h - y1, ans);
    }
  } else {
    ans = min((double)0, ans);
  }
  if (w > x1) {
    if (width + w <= W) {
      ans = min((double)w - x1, ans);
    }
  } else {
    ans = min((double)0, ans);
  }
  if (H - h < y2) {
    long long c = H - h;
    if (c - height >= 0) {
      ans = min(ans, (double)y2 - c);
    }
  } else {
    long long c = H - h;
    ans = min(ans, (double)0);
  }
  if (W - w < x2) {
    long long c = W - w;
    if (c - width >= 0) {
      ans = min(ans, (double)x2 - c);
    }
  } else {
    long long c = W - w;
    ans = min(ans, (double)0);
  }
  if (ans == 1e9)
    cout << -1 << "\n";
  else {
    cout << fixed << setprecision(6) << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
