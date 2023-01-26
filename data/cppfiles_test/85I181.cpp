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
    int flag = 2;
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] != s[i + 1]) {
        res++;
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
        if (s[0] != s[1] && s[s.length() - 1] != s[s.length() - 2]) {
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
