#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int grp0 = 0;
    bool it = true;
    int cnt0 = 0, cnt1 = 0;
    for (char c : s) {
      if (c == '0') {
        cnt0++;
        if (it) grp0++;
        it = false;
      } else {
        cnt1++;
        it = true;
      }
    }
    if (cnt1 == 0)
      cout << 1 << endl;
    else if (cnt0 == 0)
      cout << 0 << endl;
    else if (grp0 >= 2)
      cout << 2 << endl;
    else
      cout << grp0 << endl;
  }
  return 0;
}
