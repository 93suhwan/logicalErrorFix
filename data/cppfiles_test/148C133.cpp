#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y, k, d, mx[4], mn[4];
  for (int i = 0; i < 4; i++) mx[i] = 0, mn[i] = 10000000000LL;
  cin >> x >> y;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> d;
    mx[0] = max(mx[0], d);
    mn[0] = min(mn[0], d);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> d;
    mx[1] = max(mx[1], d);
    mn[1] = min(mn[1], d);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> d;
    mx[2] = max(mx[2], d);
    mn[2] = min(mn[2], d);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> d;
    mx[3] = max(mx[3], d);
    mn[3] = min(mn[3], d);
  }
  cout << max({x * (mx[2] - mn[2]), x * (mx[3] - mn[3]), y * (mx[0] - mn[0]),
               y * (mx[1] - mn[1]), mx[0] * (mx[2] - mn[2]),
               (x - mn[0]) * (mx[3] - mn[3]), mx[2] * (mx[0] - mn[0]),
               (y - mn[2]) * (mx[1] - mn[1]), mx[1] * (mx[2] - mn[2]),
               (x - mn[1]) * (mx[3] - mn[3]), mx[3] * (mx[0] - mn[0]),
               (y - mn[3]) * (mx[1] - mn[1])});
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
