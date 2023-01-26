#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
long long c[20];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(c, 0, sizeof(c));
    int fa = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7')
        continue;
      else
        fa = s[i] - '0';
    }
    if (fa != -1) {
      cout << 1 << endl;
      cout << fa << endl;
    } else {
      for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
          c[2]++;
        }
        if (s[i] == '3') {
          c[3]++;
        }
        if (s[i] == '5') {
          c[5]++;
        }
        if (s[i] == '7') {
          c[7]++;
        }
      }
      for (int i = 0; i < 10; i++) {
        if (c[i] >= 2) {
          fa = i;
          break;
        }
      }
      if (fa != -1) {
        cout << 2 << endl;
        cout << fa << fa << endl;
      } else {
        for (int i = 1; i < 1 << n; i++) {
          int now = 0, cc = 0;
          for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
              now *= 10;
              now += s[j] - '0';
              cc++;
            }
          }
          int fa1 = 0;
          for (int j = 2; j <= sqrt(now); j++) {
            if (now % j == 0) fa1 = 1;
          }
          if (fa1 == 1) {
            cout << cc << endl;
            cout << now << endl;
            break;
          }
        }
      }
    }
  }
  return 0;
}
