#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 1;
    cin >> n;
    int d = 2;
    int a[120];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (a[i] % d != 0) {
          d++;
          i = 0;
        } else
          continue;
        if (d > a[i]) {
          flag = 0;
          break;
        } else {
          flag = 1;
        }
      }
      if (i % 2 != 0) {
        if (a[i] % d != 0) {
          d++;
          i = 0;
        } else
          continue;
        if (d > a[i]) {
          flag = 0;
          break;
        } else {
          flag = 1;
        }
      }
    }
    if (flag == 1) {
      cout << d << endl;
    } else
      cout << "0" << endl;
  }
}
