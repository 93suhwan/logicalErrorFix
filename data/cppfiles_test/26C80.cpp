#include <bits/stdc++.h>
using namespace std;
char s[20];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int ans, i;
    cin >> s + 1;
    int t1 = 0, t2 = 0, c1 = 5, c2 = 5;
    for (i = 1; i <= 10; i++) {
      if (i % 2 != 0) {
        c1--;
        if (s[i] == '1' || s[i] == '?') t1++;
        if (t1 > t2 + c2 || t2 > t1 + c1) break;
      } else {
        c2--;
        if (s[i] == '1') t2++;
        if (t1 > t2 + c2 || t2 > t1 + c1) break;
      }
    }
    if (i > 10)
      ans = 10;
    else
      ans = i;
    t1 = t2 = 0, c1 = c2 = 5;
    for (i = 1; i <= 10; i++) {
      if (i % 2 != 0) {
        c1--;
        if (s[i] == '1') t1++;
        if (t1 > t2 + c2 || t2 > t1 + c1) break;
      } else {
        c2--;
        if (s[i] == '1' || s[i] == '?') t2++;
        if (t1 > t2 + c2 || t2 > t1 + c1) break;
      }
    }
    if (i > 10)
      ans = min(ans, 10);
    else
      ans = min(ans, i);
    cout << ans << endl;
  }
  return 0;
}
