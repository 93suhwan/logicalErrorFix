#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int x = s.length();
    int n = s.length();
    if (n % 2 != 0) {
      cout << "NO" << endl;
    } else {
      n = (n / 2);
      string a = "", b = "";
      for (int i = 0; i < n; i++) {
        a += s[i];
      }
      for (int i = n; i < x; i++) {
        b += s[i];
      }
      if (a == b)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
