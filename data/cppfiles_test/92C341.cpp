#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    int cnt_ab = 0, cnt_ba = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == 'a' && str[i + 1] == 'b') cnt_ab++;
      if (str[i] == 'b' && str[i + 1] == 'a') cnt_ba++;
    }
    if (cnt_ab == cnt_ba)
      cout << str << endl;
    else {
      if (str[0] == 'a')
        str[0] = 'b';
      else
        str[0] = 'a';
      cout << str << endl;
    }
  }
}
