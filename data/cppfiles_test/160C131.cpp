#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void checkr(int r, int n, int& dr) {
  if (r > n)
    dr = -1;
  else if (r < 1)
    dr = 1;
}
void checkc(int c, int m, int& dc) {
  if (c > m)
    dc = -1;
  else if (c < 1)
    dc = 1;
}
void solve() {
  int n, m, r1, r2, c1, c2;
  cin >> n >> m >> r1 >> c1 >> r2 >> c2;
  int r = r1, c = c1, ans = 0, dr = 1, dc = 1;
  while (r != r2 && c != c2) {
    checkr(r + dr, n, dr);
    checkc(c + dc, m, dc);
    r += dr;
    c += dc;
    ans++;
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
