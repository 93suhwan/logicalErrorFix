#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, a, b, s1;
  cin >> t;
  char s;
  for (int i = 0; i < t; i++) {
    cin >> n;
    a = 0;
    for (int j = 0; j < n; j++) {
      cin >> s;
      if (s == '0') {
        s1 = 0;
      } else if (s == '1') {
        s1 = 1;
      } else if (s == '2') {
        s1 = 2;
      } else if (s == '3') {
        s1 = 3;
      } else if (s == '4') {
        s1 = 4;
      } else if (s == '5') {
        s1 = 5;
      } else if (s == '6') {
        s1 = 6;
      } else if (s == '7') {
        s1 = 7;
      } else if (s == '8') {
        s1 = 8;
      } else if (s == '9') {
        s1 = 9;
      }
      if (s1 == 0) {
        a = a;
      } else if (j + 1 == n) {
        a = a + s1;
      } else {
        a = a + 1 + s1;
      }
    }
    cout << a << endl;
  }
}
