#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> s + 1;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'R') {
        for (int j = i - 1; j >= 1; j--) {
          if (s[j] == '?') {
            if (s[j + 1] == 'R') {
              s[j] = 'B';
            } else
              s[j] = 'R';
          } else
            break;
        }
        while (i <= n) {
          i++;
          if (s[i] == '?') {
            if (s[i - 1] == 'R') {
              s[i] = 'B';
            } else
              s[i] = 'R';
          } else {
            i--;
            break;
          }
        }
      } else if (s[i] == 'B') {
        for (int j = i - 1; j >= 1; j--) {
          if (s[j] == '?') {
            if (s[j + 1] == 'R') {
              s[j] = 'B';
            } else
              s[j] = 'R';
          } else
            break;
        }
        while (i <= n) {
          i++;
          if (s[i] == '?') {
            if (s[i - 1] == 'R') {
              s[i] = 'B';
            } else
              s[i] = 'R';
          } else {
            i--;
            break;
          }
        }
      }
    }
    if (s[1] == '?') {
      for (int i = 1; i <= n; i++) {
        s[i] = (i % 2) ? 'B' : 'R';
      }
    }
    cout << s + 1 << endl;
  }
}
