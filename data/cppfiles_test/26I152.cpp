#include <bits/stdc++.h>
using namespace std;
string s;
int t, a, b, a1, b1;
int main() {
  cin >> t;
  while (t) {
    cin >> s;
    a = a1 = 0;
    b = b1 = 0;
    for (int i = 0; i < 10; i++) {
      if (s[i] == '0') {
        if (i % 2 == 0) {
          if ((9 - i) / 2 + a < b + b1) {
            cout << i + 1 << endl;
            break;
          }
        } else {
          if ((9 - i) / 2 + b < a + a1) {
            cout << i + 1 << endl;
            break;
          }
        }
      }
      if (s[i] == '1') {
        if (i % 2 == 0) {
          a++;
          if (10 - i - 1 - ((9 - i) / 2) + b < a + a1) {
            cout << i + 1 << endl;
            break;
          }
        } else {
          b++;
          if (10 - i - 1 - ((9 - i) / 2) + a < b + b1) {
            cout << i + 1 << endl;
            break;
          }
        }
      }
      if (s[i] == '?') {
        if (i % 2 == 0) {
          a1++;
          if (10 - i - 1 - ((9 - i) / 2) + b < a + a1) {
            cout << i + 1 << endl;
            break;
          }
        } else {
          b1++;
          if (10 - i - 1 - ((9 - i) / 2) + a < b + b1) {
            cout << i + 1 << endl;
            break;
          }
        }
      }
      if (i == 9) cout << 10 << endl;
    }
    t--;
  }
}
