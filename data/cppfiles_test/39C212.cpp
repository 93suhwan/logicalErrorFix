#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
void solve(int ttt) {
  long long int W, H;
  cin >> W >> H;
  long long int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long int w, h;
  cin >> w >> h;
  long long int l = x2 - x1, b = y2 - y1;
  long long int ans = 1e9;
  if (w + l > W && h + b > H) {
    cout << "-1\n";
    return;
  }
  if (w + l <= W) {
    ans = min(ans, abs(max(x1, w) - x1));
    ans = min(ans, abs(min(x2, W - w) - x2));
  }
  if (h + b <= H) {
    ans = min(ans, abs(max(y1, h) - y1));
    ans = min(ans, abs(min(y2, H - h) - y2));
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  cin >> ttt;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
