#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
long long mod = 1e9 + 7;
bool solve(long long l, long long r, long long mx, long long& ans) {
  if (r - l + 1 > mx) {
    return false;
  }
  ans = -l + 1;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int x = 0, y = 0, mnx = 0, mxx = 0, mny = 0, mxy = 0;
    long long ansX = 1, ansY = 1;
    for (auto i : s) {
      x += i == 'D';
      x -= i == 'U';
      y += i == 'R';
      y -= i == 'L';
      mnx = min(x, mnx);
      mxx = max(x, mxx);
      mny = min(y, mny);
      mxy = max(y, mxy);
      long long tmpX, tmpY;
      if (solve(mnx, mxx, n, tmpX) && solve(mny, mxy, m, tmpY)) {
        ansX = tmpX, ansY = tmpY;
        continue;
      }
      break;
    }
    cout << ansX << " " << ansY << '\n';
  }
}
