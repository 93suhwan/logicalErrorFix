#include <bits/stdc++.h>
using namespace std;
int T;
char s[110];
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> s + 1;
    int len = strlen(s + 1);
    if (s[1] == s[len]) {
      cout << s + 1 << endl;
      continue;
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 1;; i++) {
      if (s[i] != s[len])
        sum1++;
      else
        break;
    }
    for (int i = len;; i--) {
      if (s[i] != s[1])
        sum2++;
      else
        break;
    }
    if (sum1 <= sum2) {
      for (int i = 1;; i++) {
        if (s[i] != s[len])
          s[i] = s[len];
        else
          break;
      }
    } else {
      for (int i = len;; i--) {
        if (s[i] != s[1])
          s[i] = s[1];
        else
          break;
      }
    }
    cout << s + 1 << endl;
  }
  return 0;
}
