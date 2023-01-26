#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a[4];
    long long mixn = 100000001, next, ans = 0;
    for (int i = 1; i <= 3; i++) {
      cin >> a[i];
      a[i] %= 2;
      if (a[i] == 0) ans++;
    }
    if (a[1] == a[2] == a[3])
      cout << 0 << endl;
    else if (ans == 2) {
      cout << abs(a[1] * 1 + a[2] * 2 + a[3] * 3) << endl;
    } else {
      if (a[1] == 0)
        cout << abs(a[2] * 2 - a[3] * 3) << endl;
      else
        cout << abs(a[1] - (a[2] * 2 + a[3] * 3)) << endl;
    }
  }
}
