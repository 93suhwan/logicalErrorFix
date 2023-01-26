#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, i, a = 0, b = 0, x, y, j, mn, mx, ans, jj, kk, tmp1,
                           tmp2, a1, b1, c = 0;
    string s, ss;
    cin >> n;
    cin >> s;
    ss = s;
    sort(ss.begin(), ss.end());
    x = 0;
    for (i = 0; i < n; i++) {
      if (ss[i] != s[i]) {
        x++;
      }
    }
    cout << x << endl;
  }
  return 0;
}
