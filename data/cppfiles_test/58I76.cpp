#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    string s[3];
    cin >> s[1];
    cin >> s[2];
    bool madeit = 1;
    for (int j = 0; j < n; j++) {
      if (j < n - 2) {
        if (s[1][j] == '1') {
          if (s[1][j + 1] == '1' && s[2][j + 1] == '1') {
            madeit = 0;
          }
        }
      }
    }
    if (madeit)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
