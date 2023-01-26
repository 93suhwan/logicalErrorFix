#include <bits/stdc++.h>
using namespace std;
int toint(char a) { return (a - '0'); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tst;
  cin >> tst;
  while (tst--) {
    string a, s;
    cin >> a >> s;
    long long int num = stoll(a);
    long long int sum = stoll(s);
    if (s.length() < a.length()) {
      cout << "-1\n";
    } else if (a.length() == s.length()) {
      bool no = false;
      for (int i = s.length() - 1; i >= 0; i--) {
        if ((toint(s[i]) - toint(a[i])) < 0) {
          cout << "-1\n";
          no = true;
          break;
        }
      }
      if (!no) {
        cout << stoll(s) - stoll(a) << "\n";
      }
    } else if (a.length() < s.length()) {
      int lastdigit;
      int lastsub;
      string ans;
      bool no = 0;
      int strlen = s.length();
      while (strlen > 0) {
        lastsub = num % 10;
        if (sum % 10 - num % 10 < 0) {
          lastdigit = (sum % 10) + ((sum % 100) - (sum % 10));
          sum /= 100;
          num /= 10;
          strlen -= 2;
        } else {
          lastdigit = sum % 10;
          sum /= 10;
          num /= 10;
          strlen--;
        }
        if (lastdigit - lastsub >= 0 && lastdigit - lastsub <= 9) {
          if (strlen != 0) {
            ans = to_string(lastdigit - lastsub) + ans;
          } else {
            if (lastdigit - lastsub != 0) {
              ans = to_string(lastdigit - lastsub) + ans;
            }
          }
        } else {
          cout << "-1\n";
          no = true;
          break;
        }
      }
      if (!no) {
        cout << ans << "\n";
      }
    }
  }
  return 0;
}
