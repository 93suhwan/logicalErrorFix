#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool f = 0, fl = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > 0) f = 1;
      if (a[i] < 0) fl = 1;
    }
    if (n == 1) {
      if (a[0] == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      continue;
    }
    if (f + fl == 2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
