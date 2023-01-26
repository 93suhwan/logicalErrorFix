#include <bits/stdc++.h>
using namespace std;
string s;
inline void in() {
  string s;
  cin >> s;
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    bool yes = 0;
    for (int i = 1; i <= 8; i++) {
      if (i & 1) {
        for (int j = 1; j <= 8; j++) {
          cout << i << ' ' << j << endl;
          in();
          if (s == "Done") {
            yes = 1;
            break;
          }
        }
      } else {
        for (int j = 8; j; j--) {
          cout << i << ' ' << j << endl;
          in();
          if (s == "Done") {
            yes = 1;
            break;
          }
        }
      }
      if (yes) {
        break;
      }
    }
  }
}
