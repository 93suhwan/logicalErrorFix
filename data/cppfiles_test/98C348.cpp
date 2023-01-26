#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, k, mx = 0, mn = 1e9, t = 0, x, y, s = 0;
  string s1, s2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s1;
    cin >> s2;
    for (int j = 0; j < s2.size(); j++) {
      for (int l = 0; l < s1.size(); l++) {
        if (t == 0) {
          if (s2[j] - 0 == s1[l] - 0) {
            x = l + 1;
            t++;
            break;
          }
        } else {
          if (s2[j] - 0 == s1[l] - 0) {
            y = l + 1;
            s = s + abs(x - y);
            x = y;
            break;
          }
        }
      }
    }
    cout << s << endl;
    t = 0;
    s = 0;
  }
  return 0;
}
