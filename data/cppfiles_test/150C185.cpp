#include <bits/stdc++.h>
using namespace std;
int n, a[110], g, ans;
bitset<10> vis;
void check(int x, int y) {
  vis.reset(), vis[g = 0] = 1;
  for (int i = 1; i <= x; ++i) vis |= vis << 1;
  for (int i = 1; i <= y; ++i) vis |= vis << 2;
  for (int i = 1, z; i <= n; ++i) {
    z = a[i] % 3;
    if (a[i] >= 3 && vis[z + 3])
      g = max(g, a[i] / 3 - 1);
    else if (vis[z])
      g = max(g, a[i] / 3);
    else
      return;
  }
  ans = min(ans, g + x + y);
}
void Solve_Test() {
  cin >> n, ans = 1e9;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) check(i, j);
  cout << ans << endl;
}
const bool BASE = 1;
int T = 1;
int main() {
  if (BASE) cin >> T;
  while (T--) Solve_Test();
  return 0;
}
