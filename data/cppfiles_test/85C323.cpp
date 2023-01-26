#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d\n", &T);
  for (int t = 0; t < T; t++) {
    string s;
    getline(cin, s);
    bool p = false;
    int prevZero = -1;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c == '0') {
        if (prevZero >= 0 && i - prevZero > 1) {
          cout << 2 << "\n";
          p = true;
          break;
        }
        prevZero = i;
      }
    }
    if (!p) {
      if (prevZero == -1) {
        cout << 0 << "\n";
      } else {
        cout << 1 << "\n";
      }
    }
  }
  return 0;
}
