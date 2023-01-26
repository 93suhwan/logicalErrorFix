#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l = 0;
    int r = m - 1;
    int u = 0;
    int d = n - 1;
    int pos = 0;
    int neg = 0;
    int posu = 0;
    int negd = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L') {
        if (l == n - 1)
          pos++;
        else
          l++;
        if (r == 0)
          neg++;
        else
          r--;
      }
      if (s[i] == 'R') {
        if (l == 0)
          pos++;
        else
          l--;
        if (r == n - 1)
          neg++;
        else
          r++;
      }
      if (s[i] == 'U') {
        if (u == m - 1)
          posu++;
        else
          u++;
        if (d == 0)
          negd++;
        else
          d--;
      }
      if (s[i] == 'D') {
        if (u == 0)
          posu++;
        else
          u--;
        if (d == m - 1)
          negd++;
        else
          d++;
      }
    }
    if (pos >= neg)
      cout << l + 1 << " ";
    else
      cout << r + 1 << " ";
    if (posu >= negd)
      cout << u + 1 << " ";
    else
      cout << d + 1 << " ";
    cout << endl;
  }
}
