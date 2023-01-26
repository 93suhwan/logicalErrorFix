#include <bits/stdc++.h>
using namespace std;
const int32_t mod = 1000000007;
const int32_t mod2 = 998244353;
const int32_t MAXN = 1000005;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int r = 0, c = 0;
  int mxr = 0, mxd = 0;
  int mnl = 0, mnu = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'R')
      c++;
    else if (s[i] == 'L')
      c--;
    else if (s[i] == 'U')
      r--;
    else
      r++;
    mxr = max(mxr, c);
    mnl = min(mnl, c);
    mxd = max(mxd, r);
    mnu = min(mnu, r);
    if ((mxr - mnl) == m || (mxd - mnu) == n) {
      if (s[i] == 'L') mnl++;
      if (s[i] == 'U') mnu++;
      cout << 1 - mnu << " " << 1 - mnl << endl;
      return;
    }
  }
  cout << 1 - mnu << " " << 1 - mnl << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
