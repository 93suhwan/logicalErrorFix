#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  cin >> t;
  int i;
  for (i = 1; i <= t; i++) {
    int n;
    char c;
    cin >> n >> c;
    int j, nod = 0;
    string s;
    cin >> s;
    bool fl = true;
    for (j = 0; j < s.size(); j++) {
      if (s[j] != c) {
        fl = false;
      }
    }
    if (fl == true)
      cout << 0 << endl;
    else if (s[n - 1] == c)
      cout << 1 << endl << n << endl;
    else {
      for (j = n / 2; j <= n; j++) {
        if (s[j] == c) {
          cout << 1 << endl << j + 1 << endl;
          fl = true;
          break;
        }
      }
      if (fl == false) {
        cout << 2 << endl << n << " ";
        for (j = 2; j < n; j++) {
          if (n % j != 0) {
            cout << j << endl;
            break;
          }
        }
      }
    }
  }
  return 0;
}
