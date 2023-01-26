#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int test = 1, c;
  cin >> test;
  for (c = 0; c < test; c++) {
    int n, b, d;
    cin >> n;
    string s;
    cin >> s;
    int pos = -1;
    for (b = 0; b < n; b++) {
      if (s[b] == '0') {
        pos = b + 1;
        break;
      }
    }
    if (pos == -1) {
      cout << "1"
           << " " << n / 2 << " " << (n + 2) / 2 << " " << n << endl;
    } else {
      if (pos > (n + 1) / 2) {
        cout << "1"
             << " " << pos << " "
             << "1"
             << " " << pos - 1 << endl;
      } else {
        cout << pos << " " << n << " " << pos + 1 << " " << n << endl;
      }
    }
  }
}
