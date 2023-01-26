#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, ans = 0;
  string s;
  string ans1;
  cin >> t;
  while (t--) {
    ans = 0;
    ans1 = "";
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if ((s[i] - '0') % 2 == 0 && (s[i] - '0') > 2) {
        ans = 1;
        ans1 = s[i];
      } else if (s[i] == '1') {
        ans = 1;
        ans1 = '1';
      } else if (s[i] == '9') {
        ans = 1;
        ans1 = '9';
      }
    }
    if (ans == 0) {
      for (int i = 0; i < n; i++) {
        if (ans != 0) {
          break;
        }
        if (s[i] == '2') {
          for (int j = i + 1; j < n; j++) {
            if (s[j] != '3' && s[j] != '9') {
              ans = 2;
              ans1 += '2';
              ans1 += s[j];
              break;
            }
          }
        } else if (s[i] == '3') {
          for (int j = i + 1; j < n; j++) {
            if (s[j] != '7') {
              ans = 2;
              ans1 += '3';
              ans1 += s[j];
              break;
            }
          }
        } else if (s[i] == '5') {
          for (int j = i + 1; j < n; j++) {
            if (s[j] != '3') {
              ans = 2;
              ans1 += '5';
              ans1 += s[j];
              break;
            }
          }
        } else if (s[i] == '7') {
          for (int j = i + 1; j < n; j++) {
            if (s[j] != '3') {
              ans = 2;
              ans1 += s[i];
              ans1 += s[j];
              break;
            }
          }
        }
      }
    }
    if (ans > 0) {
      cout << ans << endl;
      cout << ans1 << endl;
    } else {
      cout << n << endl;
      cout << s << endl;
    }
  }
  return 0;
}
