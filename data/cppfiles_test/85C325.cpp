#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    int len = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '0') break;
      len++;
    }
    int f = 0;
    int f1 = 0, f2 = 0;
    for (int i = 0; i < s.size() - len; i++) {
      if (s[i] == '0') f = 1;
      if (f) {
        if (s[i] == '0')
          f1 = 1;
        else
          f2 = 1;
      }
    }
    if (f1 && f2)
      puts("2");
    else if (f1 && !f2)
      puts("1");
    else if (!f1 && f2)
      puts("0");
    else if (!f1 && !f2)
      puts("0");
  }
  return 0;
}
