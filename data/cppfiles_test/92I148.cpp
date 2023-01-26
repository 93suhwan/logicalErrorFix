#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int ab = 0, ba = 0, k;
    string a;
    cin >> a;
    int len = a.length();
    for (int i = 0; i < len; i++) {
      if (a[i] == 'a' && a[i + 1] == 'b') {
        ab++;
        i++;
      } else if (a[i] == 'b' && a[i + 1] == 'a') {
        ba++;
        i++;
      } else if (a[i] == 'a' && a[i + 1] == 'a') {
        continue;
      } else if (a[i] == 'b' && a[i + 1] == 'b') {
        continue;
      }
    }
    if (ab == ba) {
      cout << a << "\n";
    } else {
      k = abs(ba - ab);
      if (ab > ba) {
        for (int i = 0; i < len; i++) {
          while (k--) {
            if (a[i] == 'a' && a[i + 1] == 'b') {
              if (a[i - 1] != 'a') {
                a[i] = 'b';
              } else {
                a[i + 1] = 'a';
              }
              i++;
            }
          }
          break;
        }
      } else {
        for (int i = 0; i < len; i++) {
          while (k--) {
            if (a[i] == 'b' && a[i + 1] == 'a') {
              if (a[i - 1] != 'b') {
                a[i] = 'a';
              } else {
                a[i + 1] = 'b';
              }
              i++;
            }
          }
          break;
        }
      }
      cout << a << "\n";
    }
  }
}
