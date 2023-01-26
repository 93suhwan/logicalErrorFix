#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c1;
    cin >> n;
    string a, b;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
      if (((a[i] == 0 && a[i + 1] == 0) ||
           (a[i] == 0 && ((b[i] == 0) || (b[i + 1] == 0))))) {
        c1 = 1;
      } else {
        c1 = 0;
      }
    }
    if (c1 == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
