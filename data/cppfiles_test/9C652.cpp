#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int i;
  string s;
  char c;
  for (i = 1; i <= t; i++) {
    int r = 0, w = 0, rs = 0, ws = 0, k = 0;
    cin >> s;
    for (int j = 97; j <= 122; j++) {
      k = 0;
      for (int m = 0; m < s.length(); m++) {
        c = s.at(m);
        if (int(c) == j) {
          k++;
        }
      }
      if (k == 1) {
        rs++;
      } else if (k >= 2) {
        r++;
        w = w + (k - 2);
      }
    }
    if (rs % 2 == 0) {
      rs = rs / 2;
    } else {
      rs = rs - 1;
      rs = rs / 2;
    }
    r = r + rs;
    cout << r << "\n";
  }
  return 0;
}
