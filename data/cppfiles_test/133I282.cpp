#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int mxn = 1e4 + 4;
;
void solve() {
  long long int n, m, a, b, c, d, e, x, y, cn = 0, cn1 = 0, sm1 = 0, sm = 0,
                                           mx = -1e18, mn = 1e18, i, j, k;
  string ss, s, sr;
  bool f = false, ff = false;
  cin >> n;
  string str[n];
  for (i = 0; i < n - 2; i++) cin >> str[i];
  s = str[0];
  ss = str[0];
  for (i = 1; i < n - 2; i++) {
    sr = str[i];
    if (sr[0] == ss[1])
      s += sr[1];
    else
      s += sr;
    ss = sr;
  }
  cout << s << endl;
}
int main() {
  int z;
  cin >> z;
  while (z--) {
    solve();
  }
  return 0;
}
