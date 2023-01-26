#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char a[N];
int v[N];
int r[N];
int b[N];
void solve() {
  int n, m, k, n1 = 0, n2 = 0, ans = 0, x0, dx = 0, dy = 0, s = 0, lx = 1,
               ly = 1, rx, ry, myx = 1, myy = 1;
  cin >> n >> m;
  rx = n;
  ry = m;
  cin >> a + 1;
  k = strlen(a + 1);
  for (int i = 1; i <= k; i++) {
    if (a[i] == 'D') dx++;
    if (a[i] == 'U') dx--;
    if (a[i] == 'R') dy++;
    if (a[i] == 'L') dy--;
    if (dx < 0)
      lx = max(lx, abs(dx) + 1);
    else
      rx = min(rx, n - dx);
    if (dy < 0)
      ly = max(ly, abs(dy) + 1);
    else
      ry = min(ry, m - dy);
    if (lx <= rx) myx = lx;
    if (ly <= ry) myy = ly;
  }
  cout << myx << " " << myy << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
