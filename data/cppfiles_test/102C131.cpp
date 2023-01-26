#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long r = 1, c = 1, cr = 1, cc = 1;
    long long mnr = 1, mnc = 1, mxr = 1, mxc = 1;
    for (char ch : s) {
      if (ch == 'R') {
        if (cc + 1 > m) {
          if (mnc == 1) break;
          c--;
          mnc--;
        } else
          cc++;
      } else if (ch == 'L') {
        if (cc - 1 < 1) {
          if (mxc == m) break;
          c++;
          mxc++;
        } else
          cc--;
      } else if (ch == 'U') {
        if (cr - 1 < 1) {
          if (mxr == n) break;
          r++;
          mxr++;
        } else
          cr--;
      } else {
        if (cr + 1 > n) {
          if (mnr == 1) break;
          r--;
          mnr--;
        } else
          cr++;
      }
      mnr = min(mnr, cr);
      mxr = max(mxr, cr);
      mnc = min(mnc, cc);
      mxc = max(mxc, cc);
    }
    cout << r << " " << c << '\n';
  }
  return 0;
}
