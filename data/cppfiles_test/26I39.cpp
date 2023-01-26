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
      if (i % 2) {
        if ((s[i] == '?' && second > first) || s[i] == '1') {
          s[i] = '1';
          second++;
        }
        s[i] = '0';
        rems = (n - i - 1) / 2;
      } else {
        if ((s[i] == '?' && first > second) || s[i] == '1') {
          s[i] = '1';
          first++;
        }
        s[i] = '0';
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
