#include <bits/stdc++.h>
using namespace std;
int di[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dj[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const long long N = 1e5 + 5, MOD = 1e9 + 7, oo = 1e18;
int t, i, j, n, m, k, mex, mey, curx, cury;
string s;
map<char, int> mpx, mpy;
bool valid(int x, int y) { return (x >= 1 && x <= n && y >= 1 && y <= m); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mpy['L'] = -1, mpy['R'] = 1, mpx['U'] = -1, mpx['D'] = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m >> s;
    k = s.length();
    curx = cury = 0;
    int mnx = 0, mxx = 0, mny = 0, mxy = 0;
    for (i = 0; i < k; i++) {
      if (s[i] == 'L') {
        cury--;
        mny = min(mny, cury);
        if (-mny + mxy == m) {
          mny++;
          break;
        }
      }
      if (s[i] == 'R') {
        cury++;
        mxy = max(mxy, cury);
        if (-mny + mxy == m) {
          mxy--;
          break;
        }
      }
      if (s[i] == 'U') {
        curx--;
        mnx = min(mnx, curx);
        if (-mnx + mxx == n) {
          mnx++;
          break;
        }
      }
      if (s[i] == 'D') {
        curx++;
        mxx = max(mxx, curx);
        if (-mnx + mxx == n) {
          mxx--;
          break;
        }
      }
    }
    cout << -mnx + 1 << " " << -mny + 1 << endl;
  }
  return 0;
}
