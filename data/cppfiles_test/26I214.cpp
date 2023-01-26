#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int first = 0, second = 0, n = s.length(), b = 0, rems = 5, remf = 5;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && i % 2) second++;
      if (s[i] == '1' && i % 2 == 0) first++;
    }
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        if ((s[i] == '?' && second >= first)) {
          s[i] = '1';
          second++;
        }
      } else {
        if ((s[i] == '?' && first >= second)) {
          s[i] = '1';
          first++;
        }
      }
    }
    second = first = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        if (s[i] == '1') second++;
        rems = (n - i - 1) / 2;
      } else {
        if (s[i] == '1') first++;
        remf = (n - i - 1) / 2;
      }
      if (second > first && first + remf < second) {
        b = i;
        break;
      }
      if (second < first && second + rems < first) {
        b = i;
        break;
      }
    }
    if (!b) b = 9;
    cout << b + 1 << endl;
  }
}
