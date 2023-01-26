#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, a[105];
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 1, flag = 1, add = 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      int x;
      x = a[i];
      if (flag == 1) {
        if (x == 1) {
          sum += add;
          add = 5;
        } else if (x == 0) {
          add = 1;
          flag = 0;
        }
      } else if (flag == 0) {
        if (x == 1) {
          flag = 1;
          sum += add;
          add = 5;
        } else if (x == 0) {
          sum = -1;
          break;
        }
      }
    }
    cout << sum << endl;
  }
}
