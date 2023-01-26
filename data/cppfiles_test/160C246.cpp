#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int x, y, a, b;
  cin >> x >> y >> a >> b;
  long long int xpos = x;
  long long int ypos = y;
  long long int ans = 0;
  long long int dx = 1, dy = 1;
  while (xpos != a && ypos != b) {
    if (xpos == n && dx == 1) {
      dx *= -1;
    } else if (xpos == 0 && dx == -1) {
      dx *= -1;
    }
    if (ypos == m && dy == 1) {
      dy *= -1;
    } else if (ypos == 0 && dy == -1) {
      dy *= -1;
    }
    xpos += dx;
    ypos += dy;
    ans++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
    cout << '\n';
  }
  return 0;
}
