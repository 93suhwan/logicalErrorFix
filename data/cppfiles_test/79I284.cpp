#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int flag = 0;
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '5' ||
          s[i] == '6' || s[i] == '8') {
        flag = 1;
        cout << "2\n" << s[0] << s[i] << "\n";
        break;
      }
    }
    if (flag)
      ;
    else if (s[0] == '4' || s[0] == '6' || s[0] == '8' || s[0] == '9')
      cout << "1\n" << s[0] << "\n";
    else {
      int ad = 1;
      for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
          if (s[i] == s[j])
            if (s[i] != '1') {
              cout << "2\n" << s[i] << s[j] << "\n";
              ad = 0;
            } else if ((s[i] + s[j] - '0' - '0') % 3 == 0) {
              cout << "2\n" << s[i] << s[j] << "\n";
              ad = 0;
            }
        }
        if (ad) {
          int sum = 0;
          for (int i = 0; i < s.size(); i++) sum += s[i] - '0';
          if (sum % 3 == 0) cout << s.size() << "\n" << s << '\n';
        }
      }
    }
  }
}
