#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(int TestCase) {
  int n, m, y, x, r, c;
  cin >> n >> m >> y >> x >> r >> c;
  int dy = 1, dx = 1, ret = 0;
  while (true) {
    if (y == r || x == c) break;
    auto ny = y + dy;
    auto nx = x + dx;
    if (ny < 1 || ny > n) dy *= -1;
    if (nx < 1 || nx > m) dx *= -1;
    y += dy, x += dx, ret++;
  }
  cout << ret << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (auto i = 1; i <= t; ++i) {
    solve(i);
  }
}
