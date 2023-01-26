#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    string str;
    cin >> str;
    int num = str.length();
    int p = num / 2, count = 0;
    if (num % 2 != 0)
      cout << "NO" << endl;
    else {
      for (int i = 0; i < num / 2; i++) {
        if (str[i] == str[p]) {
          p++;
        } else {
          count = 1;
          break;
        }
      }
      if (count == 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
    t--;
  }
  return 0;
}
