#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
double dist(long long int x1, long long int y1, long long int x2,
            long long int y2) {
  long long int sq = (x1 - x2) * (x1 - x2);
  sq += (y1 - y2) * (y1 - y2);
  return sqrt(double(sq));
}
void solve(int ttt) {
  long long int W, H;
  cin >> W >> H;
  long long int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long int w, h;
  cin >> w >> h;
  long long int l = x2 - x1, b = y2 - y1;
  if (0 <= x1 && x1 <= W - l && h <= y1 && y1 <= H - b) {
    cout << "0\n";
    return;
  }
  if (0 <= y1 && y1 <= H - b && w <= x1 && x1 <= W - l) {
    cout << "0\n";
    return;
  }
  double ans = 1e10;
  1;
  1;
  1;
  if (H >= h + b) {
    ans = min(ans, dist(x1, y1, x1, h));
  }
  if (W >= w + l) {
    ans = min(ans, dist(x1, y1, w, y1));
  }
  1;
  cout << fixed << setprecision(10) << (ans == 1e10 ? -1 : ans) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  cin >> ttt;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
