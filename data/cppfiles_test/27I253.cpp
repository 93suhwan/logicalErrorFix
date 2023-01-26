#include <bits/stdc++.h>
using namespace std;
char s[100005];
char t[100005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    cin >> t;
    int len_s = strlen(s), len_t = strlen(t);
    if (len_t > len_s) {
      cout << "NO" << endl;
      continue;
    }
    int i = 0, j = 0;
    bool flag = false;
    for (i = 0; i < (int)strlen(s); i++) {
      if (t[j] == s[i]) {
        j++;
        for (int k = 1; k + i < len_s; k += 3) {
          if (s[i + k] == t[j]) {
            j++;
            k = -2;
          }
          if (j == len_t) {
            flag = true;
            break;
          }
        }
        j = 0;
      }
      if (flag) break;
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
