#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c, d, x, y;
  int cnt = 0;
  cin >> a >> b >> c >> d >> x >> y;
  int dx = 1;
  int dy = 1;
  while (c != x and d != y) {
    if (c + dx > a) dx = -1;
    if (d + dy > b) dy = -1;
    c += dx;
    d += dy;
    cnt += 1;
  }
  cout << cnt << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
