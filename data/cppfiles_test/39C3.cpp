#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  int t;
  t = 1;
  while (t--) {
    int n, i, j, k, x;
    cin >> n;
    for (i = 1; i <= n - 1; i++) {
      cout << "? ";
      for (j = 1; j < n; j++) {
        cout << i + 1 << ' ';
      }
      cout << '1' << endl;
      cin >> k;
      if (k == 0) {
        x = i;
        break;
      } else {
        a[k] = -i;
      }
      if (i == n - 1) x = n;
    }
    for (i = 1; i <= n - 1; i++) {
      cout << "? ";
      for (j = 1; j < n; j++) {
        cout << n - i << ' ';
      }
      cout << n << endl;
      cin >> k;
      if (k == 0) {
        break;
      } else {
        a[k] = i;
      }
    }
    cout << "! ";
    for (j = 1; j < n; j++) {
      cout << a[j] + x << ' ';
    }
    cout << x << endl;
  }
  return 0;
}
