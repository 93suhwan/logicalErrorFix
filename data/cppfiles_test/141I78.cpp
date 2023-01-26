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
    int num = stoi(a);
    int sum = stoi(s);
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
        cout << stoi(s) - stoi(a) << "\n";
      }
    } else if (a.length() < s.length()) {
      int lastdigit;
      int lastsub;
      int i = 0;
      string ans;
      bool no = 0;
      while (sum % 10 > 0) {
        lastsub = num % 10;
        if (sum % 10 - num % 10 < 0) {
          lastdigit = (sum % 10) + ((sum % 100) - (sum % 10));
          sum /= 100;
          num /= 10;
        } else {
          lastdigit = sum % 10;
          sum /= 10;
          num /= 10;
        }
        if (lastdigit - lastsub >= 0 || lastdigit - lastsub <= 9) {
          ans.append(to_string(lastdigit - lastsub));
        } else {
          cout << "-1\n";
          no = true;
          break;
        }
        i++;
      }
      if (!no) {
        cout << ans << "\n";
      }
    }
  }
  return 0;
}
