#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    char ch[n];
    cin >> ch;
    int ca = 0, cb = 0;
    int l = 0, r = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
      char c1 = ch[i];
      int len = 0;
      if (c1 == 'A') {
        ca = 1;
        cb = 0;
      } else {
        cb = 1;
        ca = 0;
      }
      for (int j = i + 1; j < n; j++) {
        char c2 = ch[j];
        if (c2 == 'A') {
          ca++;
        } else {
          cb++;
        }
        if (ca == cb) {
          len++;
        }
        if (len > max) {
          max = len;
          l = i + 1;
          r = j + 1;
        }
      }
    }
    if (max != 0) {
      cout << l << " " << r << endl;
    } else {
      cout << "-1 -1" << endl;
    }
  }
}
