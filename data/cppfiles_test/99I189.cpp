#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a = 0, b = 0, firstb, endb;
    bool ch = false;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        a++;
      else {
        if (!ch) {
          firstb = i;
          ch = true;
        }
        endb = i;
        b++;
      }
    }
    if (b == 1 || b == 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            cout << "X"
                 << " ";
          } else if (s[i] == '1' || s[j] == '1') {
            cout << "="
                 << " ";
          } else {
            if (i == firstb && j == endb) {
              cout << "-"
                   << " ";
            } else if (i == endb && j == firstb) {
              cout << "+"
                   << " ";
            } else if (i < j) {
              cout << "+"
                   << " ";
            } else {
              cout << "-"
                   << " ";
            }
          }
        }
        cout << endl;
      }
    }
  }
  return 0;
}
