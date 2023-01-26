#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int first = 0, second = 0, scnt = 0, fcnt = 0, n = s.length(), b = 0,
        rems = 5, remf = 5;
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        if (s[i] == '1') second++;
        if (s[i] == '?') scnt++;
        rems--;
      } else {
        if (s[i] == '1') first++;
        if (s[i] == '?') fcnt++;
        remf--;
      }
      int temps = scnt + second, tempf = fcnt + first;
      if (temps > (first + remf)) {
        b = i + 1;
        break;
      }
      if (tempf > (second + rems)) {
        b = i + 1;
        break;
      }
    }
    if (!b) b = 10;
    cout << b << endl;
  }
}
