#include <bits/stdc++.h>
using namespace std;
int t;
string s, T;
int main() {
  cin >> t;
  while (t--) {
    cin >> s >> T;
    int n = s.size();
    int a[n];
    for (int i = 0; i < n; i++) a[i] = s[i];
    sort(a, a + n);
    int acheck = 0, bcheck = 0, ccheck = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') acheck++;
      if (s[i] == 'b') bcheck++;
      if (s[i] == 'c') ccheck++;
    }
    if (acheck == 0 || bcheck == 0 || ccheck == 0 || T != "abc") {
      for (int i = 0; i < n; i++) cout << (char)a[i];
      cout << endl;
    } else {
      for (int i = 0; i < n; i++) {
        if (a[i] == 98) {
          continue;
        }
        cout << (char)a[i];
        if (a[i] == 99) ccheck--;
        if (ccheck == 0)
          while (bcheck > 0) {
            cout << "b";
            bcheck--;
          }
      }
      cout << endl;
    }
  }
  return 0;
}
