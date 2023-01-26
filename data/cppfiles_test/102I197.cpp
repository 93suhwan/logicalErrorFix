#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
char s[N];
void solve() {
  int n, m;
  cin >> n >> m;
  scanf("%s", s + 1);
  int x = 1, y = 1;
  int dx = 0, dy = 0;
  for (register int i = 1; i <= n; ++i) {
    if (s[i] == 'L')
      dy--;
    else if (s[i] == 'R')
      dy++;
    else if (s[i] == 'D')
      dx++;
    else
      dx--;
    if (1 - dx > n || n - dx < 1 || 1 - dy > n || n - dy < 1) break;
    x = max(1 - dx, 1);
    y = max(1 - dy, 1);
  }
  cout << x << ' ' << y << '\n';
}
signed main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
