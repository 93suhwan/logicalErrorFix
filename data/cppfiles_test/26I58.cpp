#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int min1 = 0, min2 = 0, max1 = 0, max2 = 0;
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
      ans++;
      if (s[i] == '1') {
        if (i % 2 == 0) {
          min1++;
          max1++;
        } else {
          min2++;
          max2++;
        }
      } else if (s[i] == '?') {
        if (i % 2 == 0)
          max1++;
        else if (i % 2 != 0)
          max2++;
      }
      if (i % 2 == 0) {
        if (max1 + (10 - i - 1) / 2 < min2) break;
      } else {
        if (max2 + (10 - i - 1) / 2 < min1) break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
