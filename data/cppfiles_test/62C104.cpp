#include <bits/stdc++.h>
using namespace std;
inline long long md(long long m, long long v) { return ((v % m) + m) % m; }
void solve() {
  int Y, X, Q;
  cin >> Y >> X >> Q;
  long long ans = 0;
  for (int y = 0; y < Y; y++) {
    for (int x = 0; x < X; x++) {
      int x_space = X - 1 - x;
      int y_space = Y - 1 - y;
      ans++;
      {
        int R = min(x_space, y_space + 1);
        int D = min(y_space, R);
        ans += R + D;
      }
      {
        int D = min(y_space, x_space + 1);
        int R = min(x_space, D);
        ans += R + D;
      }
    }
  }
  vector<vector<int> > lock(Y, vector<int>(X, 0));
  auto fn = [&](int y, int x, int dy, int dx) -> int {
    int ret = 0;
    while (1) {
      y += dy, x += dx;
      if (y < 0 || x < 0 || y >= Y || x >= X || lock[y][x]) break;
      ret++;
      swap(dy, dx);
    }
    return ret;
  };
  while (Q--) {
    int y, x;
    cin >> y >> x;
    y--, x--;
    bool locked = lock[y][x];
    {
      int up = fn(y, x, -1, 0);
      int down = fn(y, x, 0, 1);
      ans += (locked ? 1 : -1) * ((up + 1) * (down + 1) - 1);
    }
    {
      int up = fn(y, x, 0, -1);
      int down = fn(y, x, 1, 0);
      ans += (locked ? 1 : -1) * ((up + 1) * (down + 1) - 1);
    }
    ans += (locked ? 1 : -1);
    lock[y][x] ^= 1;
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
