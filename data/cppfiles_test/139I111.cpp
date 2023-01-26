#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, h, sign;
  string str;
  scanf("%d", &t);
  getchar();
  for (int i = 0, sign = 0; i < t; i++) {
    getline(cin, str);
    h = str.length();
    if (h % 2 != 0)
      cout << "NO" << endl;
    else {
      for (int i = 0; i < h / 2; i++) {
        if (str[i] != str[(h / 2) + i]) sign = 1;
        cout << str[i] << " " << str[(h / 2) + i] << endl;
      }
      if (sign == 0)
        cout << "YES" << endl;
      else if (sign == 1)
        cout << "NO" << endl;
    }
  }
  return 0;
}
