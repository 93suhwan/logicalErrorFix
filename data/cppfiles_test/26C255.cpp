#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  cin >> t;
  while (t--) {
    string s1;
    cin >> s1;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    for (int i = 0; i < 10; i++) {
      if (s1[i] == '1') {
        if (i % 2 == 0)
          a++;
        else
          b++;
      } else if (s1[i] == '0') {
        if (i % 2 == 0)
          c++;
        else
          d++;
      } else {
        if (i % 2 == 0)
          e++;
        else
          f++;
      }
      if (a + e > 5 - f - d) {
        cout << i + 1 << endl;
        break;
      } else if (b + f > 5 - e - c) {
        cout << i + 1 << endl;
        break;
      }
      if (a > 5 - d - f) {
        cout << i + 1 << endl;
        break;
      } else if (b > 5 - c - e) {
        cout << i + 1 << endl;
        break;
      }
      if (i == 9) cout << 10 << endl;
    }
  }
  return 0;
}
