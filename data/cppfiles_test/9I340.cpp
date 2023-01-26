#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, count = 0, flag = 0, add = 0;
    string a;
    cin >> a;
    n = a.length();
    for (i = 0; i < n; i++) {
      if (a[i] != a[n - i - 1]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      if (n % 2 == 0 && a[(n - 1) / 2] == a[n / 2]) {
        add = 1;
      } else if (n % 2 != 0 && a[(n - 1) / 2] == a[n / 2]) {
        add = 1;
      } else
        add = 0;
    }
    if (n == 1)
      cout << "0" << '\n';
    else if ((flag == 1 || add == 0) && n != 1)
      cout << n / 2 << '\n';
    else if (add == 1 && n != 1)
      cout << "1" << '\n';
  }
}
