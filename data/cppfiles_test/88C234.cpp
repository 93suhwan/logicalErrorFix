#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    int f = 0;
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      if (a[i] <= a[i - 1]) {
        f = 1;
      }
    }
    if (n & 1) {
      if (f) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "YES" << endl;
    }
  }
}
