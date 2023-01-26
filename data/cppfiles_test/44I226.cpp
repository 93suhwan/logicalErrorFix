#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    int ans = 0;
    if (c == d and c != 0) {
      ans = 1;
    } else if (c == 0 and d == 0) {
      ans = 0;
    } else if (c == 0 or d == 0) {
      ans = 2;
    } else {
      int temp;
      if (c > d) {
        temp = c - d;
        if (temp % 2 == 0) {
          ans = 2;
        }
        if (temp % 2 != 0) {
          ans = -1;
        }
      }
      if (d > c) {
        temp = d - c;
        if (temp % 2 == 0) {
          ans = 2;
        }
        if (temp % 2 != 0) {
          ans = -1;
        }
      }
    }
    cout << ans << endl;
  }
}
