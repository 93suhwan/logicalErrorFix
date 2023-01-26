#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    string a = "", b = "", res = "";
    for (int i = 0; i < x; i++) {
      a += '(';
      b += ')';
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        res += a.substr(j, i + 1);
        res += b.substr(j, i + 1);
      }
      cout << res << endl;
      res = "";
    }
  }
  return 0;
}
