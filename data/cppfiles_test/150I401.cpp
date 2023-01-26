#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = a[n - 1] / 3;
    if (a[n - 1] % 3 != 0) res++;
    if (n == 1) {
      cout << res << endl;
      continue;
    }
    if (a[n - 1] % 3 == 2) {
      for (int i = 0; i < n - 1; i++) {
        if (a[i] % 3 == 1) {
          res++;
          break;
        }
      }
      cout << res << endl;
      continue;
    } else if (a[n - 1] % 3 == 1) {
      bool x = false;
      for (int i = n - 1; i >= 0; i--) {
        if (a[i] < (a[n - 1] - 3)) break;
        if (a[i] == a[n - 1] - 1 || a[i] == a[n - 1] - 3) {
          x = true;
          break;
        }
      }
      for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 2) {
          if (x) res++;
          break;
        }
      }
      cout << res << endl;
      continue;
    } else {
      bool y = false;
      for (int i = n - 1; i >= 0; i--) {
        if (a[i] == a[n - 1] - 1 || a[i] == a[n - 1] - 2) res++;
        if (a[i] % 3 != 0) {
          res++;
          break;
        }
      }
      cout << res << endl;
      continue;
    }
  }
}
