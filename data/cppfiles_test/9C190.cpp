#include <bits/stdc++.h>
using namespace std;
bool compareLetter(char a, char b) { return (a < b); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    char s[100];
    cin >> s;
    sort(s, s + strlen(s), compareLetter);
    int i;
    int r = 0, b = 0;
    if (strlen(s) > 1) r++;
    int cnt = 1;
    for (i = 1; i < strlen(s); i++) {
      if (s[i] == s[i - 1]) {
        cnt = 1;
        while (s[i] == s[i - 1] && i < strlen(s)) {
          cnt++;
          if (cnt == 2) {
            if (r == b)
              r++;
            else
              b++;
          }
          i++;
        }
      }
      if (i >= strlen(s)) break;
      if (r == b)
        r++;
      else if (r > b)
        b++;
    }
    if (r == b)
      cout << r << "\n";
    else
      cout << r - 1 << "\n";
  }
}
