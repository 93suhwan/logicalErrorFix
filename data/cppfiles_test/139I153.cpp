#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, cons;
  cin >> t;
  cons = t;
  int count = 0;
  string yesOrNo[t];
  while (t != 0) {
    string s;
    cin >> s;
    int length = s.length();
    if (length == 1 || length == 3) {
      yesOrNo[count] = "NO";
      count += 1;
    }
    if (length == 2) {
      if (s[0] == s[1]) {
        yesOrNo[count] = "YES";
      } else
        yesOrNo[count] = "NO";
      count += 1;
    }
    if (length >= 4) {
      bool flag = false;
      string square;
      for (int z = 0; z < length; z++) {
        int size = square.length();
        if (s[z] == s[0] && s[z + 1] == s[1] && size > 1) {
          string cut = s.substr(z);
          if (cut.find(square) != string::npos) {
            yesOrNo[count] = "YES";
            count += 1;
            flag = true;
            break;
          } else {
            yesOrNo[count] = "NO";
            count += 1;
            flag = true;
            break;
          }
        } else
          square += s[z];
      }
      if (flag == false) {
        yesOrNo[count] = "NO";
        count += 1;
      }
    }
    t -= 1;
  }
  for (int i = 0; i < cons; i++) cout << yesOrNo[i] << "\n";
  return 0;
}
