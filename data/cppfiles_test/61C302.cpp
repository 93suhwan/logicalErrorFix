#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int index = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        index = i;
        break;
      }
    }
    if (index == -1) {
      for (int i = 0; i < n; i++) {
        if (i % 2) {
          s[i] = 'R';
        } else {
          s[i] = 'B';
        }
      }
    }
    for (int i = index + 1; i < n; i++) {
      if (s[i] == '?') {
        if (s[i - 1] == 'R') {
          s[i] = 'B';
        } else {
          s[i] = 'R';
        }
      }
    }
    for (int i = index - 1; i >= 0; i--) {
      if (s[i] == '?') {
        if (s[i + 1] == 'R') {
          s[i] = 'B';
        } else {
          s[i] = 'R';
        }
      }
    }
    cout << s << endl;
  }
}
