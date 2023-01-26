#include <bits/stdc++.h>
using namespace std;
void Clearing_out() { return; }
template <typename Head, typename... Tail>
void Clearing_out(Head &H, Tail &...T) {
  H.clear();
  Clearing_out(T...);
}
long long int n;
void testcase() {
  long long int m;
  cin >> n >> m;
  long long int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long int dx = 1, dy = 1, ans = 0;
  while (1) {
    if (x1 == x2 || y1 == y2) {
      cout << ans << "\n";
      return;
    }
    if (x1 + dx > n) dx = -1;
    if (y1 + dy > m) dy = -1;
    if (y1 + dy < 0) dy = 1;
    if (x1 + dx < 0) dx = 1;
    x1 += dx;
    y1 += dy;
    ans++;
  }
  cout << -1 << "\n";
  return;
}
int32_t main() {
  long long int test = 1;
  cin >> test;
  long long int t = 0;
  while (test--) {
    testcase();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
