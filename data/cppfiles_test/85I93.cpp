#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size(), o = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') o++;
    }
    int z = n - o;
    if (o == n)
      cout << 0 << endl;
    else if (z == n)
      cout << 1 << endl;
    else {
      bool chk = false;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          for (int j = i; j < n; j++) {
            if (s[j] == '0')
              z--;
            else {
              chk = true;
              break;
            }
          }
        }
        if (chk) break;
      }
      if (z == 0)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
