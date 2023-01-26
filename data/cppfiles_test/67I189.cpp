#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = -1;
    if (a == b + 1 || b == a + 1)
      ans = -1;
    else {
      int diameter = abs(a - b);
      int len = 2 * diameter;
      int t1 = c + diameter;
      if (a > len || b > len)
        ans = -1;
      else if (t1 <= len) {
        ans = t1;
      } else {
        int t2 = c - diameter;
        if (t2 > 0 and t2 <= len) ans = t2;
      }
    }
    cout << ans << endl;
  }
}
