#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int e = 0, f = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '0' && b[i] == '0') {
        c++;
      }
      if (a[i] == '1' && b[i] == '1') {
        d++;
      }
      if (a[i] == '0' && b[i] == '1') {
        e++;
      }
      if (a[i] == '1' && b[i] == '0') {
        f++;
      }
    }
    if (c + e == n) {
      cout << "-1\n";
      continue;
    }
    if (c + d == n) {
      cout << "0\n";
      continue;
    }
    if ((c + d) % 2 != 0 && (e + f) % 2 == 0 && d != 0 && f != 0 &&
        (d == 1 || d != c + d)) {
      cout << min(c + d, e + f) << "\n";
      continue;
    } else if ((c + d) % 2 != 0 && d != 0 && (d == 1 || d != c + d)) {
      cout << c + d << "\n";
    } else if ((e + f) % 2 == 0 && f != 0) {
      cout << e + f << "\n";
    } else {
      cout << "-1"
           << "\n";
    }
  }
}
