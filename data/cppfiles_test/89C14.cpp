#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t) {
    int n;
    cin >> n;
    int a[n];
    int d = 0;
    for (int x = 0; x < n; x++) {
      cin >> a[x];
      int e = 0;
      for (int y = 2; y <= x + 2; y++) {
        if (a[x] % y != 0) {
          e = 1;
          break;
        }
      }
      if (e == 0) {
        d = 1;
      }
    }
    if (d == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
    t--;
  }
}
