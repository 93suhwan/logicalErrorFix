#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    int n = str.size();
    int ab = 0, ba = 0;
    for (int i = 0; i < n - 1; i++) {
      if (str[i] == 'a' and str[i + 1] == 'b')
        ab++;
      else if (str[i] == 'b' and str[i + 1] == 'a')
        ba++;
    }
    if (ab == ba) {
      cout << str << endl;
    } else {
      string ans;
      for (int i = 0; i < n; i++) {
        string temp = str;
        if (temp[i] == 'a')
          temp[i] = 'b';
        else if (temp[i] == 'b')
          temp[i] = 'a';
        int tab = 0, tba = 0;
        for (int j = 0; j < n - 1; j++) {
          if (temp[j] == 'a' and temp[j + 1] == 'b')
            tab++;
          else if (temp[j] == 'b' and temp[j + 1] == 'a')
            tba++;
        }
        if (tab == tba) {
          ans = temp;
          break;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
