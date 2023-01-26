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
    k = abs(ba - ab);
    if (ab == ba) {
      cout << a << "\n";
    } else if (k > 0) {
      if (ab > ba) {
        for (int i = 0; i < k; i++) {
          if (a[i] == 'a') {
            a[i] = 'b';
          } else {
            a[i] = 'a';
          }
        }
      } else if (ba > ab) {
        for (int i = 0; i < k; i++) {
          if (a[i] == 'b') {
            a[i] = 'a';
          } else {
            a[i] = 'b';
          }
        }
      }
      cout << a << "\n";
    }
  }
}
