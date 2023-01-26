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
    bool J = 0, O = 0;
    for (i = 0; i < (int)strlen(s); i++) {
      if (t[j] == s[i]) {
        if (i % 2)
          J = 1;
        else
          O = 1;
        j++;
        if (j == len_t) {
          if ((len_s - i) % 2) {
            flag = true;
            break;
          }
        }
        for (int k = 0; k + i + 1 < len_s; k += 2) {
          if (s[i + k + 1] == t[j]) {
            j++;
            k -= 1;
          }
          if (j == len_t) {
            if ((len_s - i - k) % 2) {
              flag = true;
              break;
            }
          }
        }
        j = 0;
        if (J && O) break;
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
