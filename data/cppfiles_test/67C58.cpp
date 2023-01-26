#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = -1;
    int d = abs(a - b);
    int len = 2 * d;
    if (a == b or b == c or c == a)
      ans = -1;
    else if (a == b + 1 || b == a + 1)
      ans = -1;
    else {
      if (a > len or b > len or c > len)
        ans = -1;
      else {
        int t1 = c + d;
        int t2 = c - d;
        if (t1 >= 1 and t1 <= len)
          ans = t1;
        else if (t2 >= 1 and t2 <= len)
          ans = t2;
        else
          ans = -1;
      }
    }
    cout << ans << endl;
  }
}
