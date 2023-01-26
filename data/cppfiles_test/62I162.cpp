#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, i, x, flag;
  while (t--) {
    flag = 1;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> x;
      if (x == 1 && flag) {
        cout << n + 1 << ' ' << i << ' ';
        flag = 0;
      } else {
        cout << i << ' ';
      }
    }
    cout << endl;
  }
}
