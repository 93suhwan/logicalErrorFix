#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char s[N];
    int num0 = 0, num1 = 0, cnt = 0, p = 0;
    cin >> s;
    char c = s[0];
    for (int i = 0; s[i]; i++) {
      if (s[i] == '0') {
        num0++;
      } else {
        num1++;
      }
      if (s[i] != c) {
        cnt++;
        if (c == '0') {
          p++;
        }
      }
      c = s[i];
    }
    if (s[strlen(s) - 1] == '0') {
      p++;
    }
    if (p >= 2) {
      cout << 2 << endl;
    } else if (p == 1 || num0 == strlen(s)) {
      cout << 1 << endl;
    } else if (num1 == strlen(s)) {
      cout << 0 << endl;
    }
  }
  return 0;
}
