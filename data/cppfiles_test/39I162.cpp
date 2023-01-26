#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Rect {
  int right, left, top, bottom;
  int height() { return top - bottom; }
  int width() { return right - left; }
  int area() { return (top - bottom) * (right - left); }
};
void solve() {
  int w, h;
  cin >> w >> h;
  Rect first, second;
  second.bottom = 0, second.left = 0;
  cin >> first.left >> first.bottom >> first.right >> first.top;
  cin >> second.right >> second.top;
  bool move_y = first.height() + second.height() <= h,
       move_x = first.width() + second.width() <= w;
  if (!move_y && !move_x) {
    cout << -1 << '\n';
    return;
  } else {
    vector<int> moves;
    if (move_x) {
      moves.push_back(second.right - first.left);
      moves.push_back(first.right - (w - second.width()));
    }
    if (move_y) {
      moves.push_back(second.top - first.bottom);
      moves.push_back(first.top - (w - second.height()));
    }
    int ans = INT_MAX;
    for (auto i : moves) {
      if (i >= 0) ans = min(ans, i);
    }
    cout << ans;
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
