#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, upmax, downmax, leftmax, rightmax, l, c, L, C;
  string s;
  cin >> n >> m >> s;
  l = c = upmax = downmax = leftmax = rightmax = 0;
  L = C = 1;
  int i;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'U')
      l--;
    else if (s[i] == 'D')
      l++;
    else if (s[i] == 'R')
      c++;
    else
      c--;
    upmax = max(upmax, -l);
    downmax = max(downmax, l);
    rightmax = max(rightmax, c);
    leftmax = max(leftmax, -c);
    if (upmax + 1 + downmax <= n && leftmax + 1 + rightmax <= m)
      L = upmax + 1, C = leftmax + 1;
    else
      break;
  }
  cout << L << ' ' << C << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
