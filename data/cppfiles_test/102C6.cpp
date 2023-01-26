#include <bits/stdc++.h>
using namespace std;
const long long SZ = 2e5 + 4;
const long long inf = 2e9;
long long n, m;
string s;
void read() { cin >> n >> m >> s; }
void solve() {
  long long curx = 0, cury = 0;
  long long mnx = 0, mxx = 0, mny = 0, mxy = 0;
  for (long long i = 0; i < s.size(); ++i) {
    if (s[i] == 'L') {
      --curx;
    } else if (s[i] == 'R') {
      ++curx;
    } else if (s[i] == 'U') {
      --cury;
    } else {
      ++cury;
    }
    if ((curx - mnx + 1) > m || (mxx - curx + 1) > m || (cury - mny + 1) > n ||
        (mxy - cury + 1) > n) {
      cout << 1 - mny << " " << 1 - mnx << "\n";
      return;
    }
    mnx = min(mnx, curx);
    mxx = max(mxx, curx);
    mny = min(mny, cury);
    mxy = max(mxy, cury);
  }
  cout << 1 - mny << " " << 1 - mnx << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    read();
    solve();
  }
  return 0;
}
