#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, m, n;
  int t;
  string s;
  cin >> t;
  while (t--) {
    int flag = 0;
    cin >> s;
    n = s.size();
    if (n % 2 == 1) {
      cout << "NO" << endl;
    } else {
      for (i = 0; i < n / 2; i++) {
        if (s[i] != s[(n / 2) + i]) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}
