#include <bits/stdc++.h>
using namespace std;
int main() {
  long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int res = 0;
    int cnt1 = -1;
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] != s[i + 1]) {
        res++;
        if (s[i] == '1') {
          flag1 = 1;
        }
        if (s[i] == '0') {
          flag2 = 1;
        }
      }
      if (res >= 3) {
        break;
      }
    }
    if (res == 0) {
      if (s[0] == '0') {
        cout << "1" << endl;
      } else {
        cout << "0" << endl;
      }
    } else if (res == 1) {
      cout << "1" << endl;
    } else {
      if (res == 2) {
        if (flag1 == 1 && flag2 == 1) {
          cout << "1" << endl;
        } else {
          cout << "2" << endl;
        }
      } else {
        cout << "2" << endl;
      }
    }
  }
}
