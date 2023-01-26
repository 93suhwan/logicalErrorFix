#include <bits/stdc++.h>
using namespace std;
int isprime(long long N) {
  if (N < 2 || (!(N & 1) && N != 2)) return 0;
  for (int i = 3; i * i <= N; i += 2) {
    if (!(N % i)) return 0;
  }
  return 1;
}
void solve() {
  int W, H, w, h, x1, x2, y1, y2;
  cin >> W >> H;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> w >> h;
  int sum = INT_MAX;
  if (W >= (x2 - x1 + w)) {
    sum = min(sum, max(0, (w - x1)));
    sum = min(sum, max(0, (w - (W - x2))));
  }
  if (H >= (y2 - y1 + h)) {
    sum = min(sum, max(0, (h - y1)));
    sum = min(sum, max(0, (h - (H - y2))));
  }
  if (sum == INT_MAX) {
    cout << "-1" << endl;
    return;
  }
  cout << fixed << setprecision(9) << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
