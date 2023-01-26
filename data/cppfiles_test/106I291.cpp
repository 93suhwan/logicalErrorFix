#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << 2 << " " << 3;
    } else {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
