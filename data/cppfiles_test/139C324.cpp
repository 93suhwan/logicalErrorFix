#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string k;
    cin >> k;
    string a = " ", b = " ";
    if (k.length() >= 1 && k.length() % 2 == 0) {
      int i;
      for (i = 0; i < k.length() / 2; i++) {
        a += k[i];
      }
      for (i = k.length() / 2; i < k.length(); i++) {
        b += k[i];
      }
      if (a == b) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
