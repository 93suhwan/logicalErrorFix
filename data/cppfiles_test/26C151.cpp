#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    int i, n = 0, m = 0, b = 0, c = 0, d = 0, re = 10, rs = 10;
    cin >> a;
    d = 5;
    for (i = 0; i < a.size(); i++) {
      if (i % 2 == 0) {
        if (a[i] != '0') n++;
      }
      if (i % 2 == 1) {
        if (a[i] == '1') m++;
        d--;
      }
      if (n > (m + d)) {
        re = i + 1;
        break;
      }
    }
    n = 0, m = 0, c = 0, d = 5;
    for (i = 0; i < a.size(); i++) {
      if (i % 2 == 1) {
        if (a[i] != '0') n++;
      }
      if (i % 2 == 0) {
        if (a[i] == '1') m++;
        d--;
      }
      if (n > (m + d)) {
        rs = i + 1;
        break;
      }
    }
    cout << min(re, rs) << endl;
  }
}
