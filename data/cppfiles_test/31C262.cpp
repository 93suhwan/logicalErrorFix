#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, sum, n, kl1 = 0, kl0 = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = 1;
    }
    if (n % 2 == 0) {
      for (int i = 0; i < n - 1; i = i + 2) {
        if (a[i] * a[i + 1] < 0) {
          if (a[i] < 0) {
            b[i] = a[i + 1];
            b[i + 1] = -1 * a[i];
          } else {
            b[i] = -1 * a[i + 1];
            b[i + 1] = a[i];
          }
        } else {
          b[i] = -1 * a[i + 1];
          b[i + 1] = a[i];
        }
      }
    } else {
      if (n > 3) {
        for (int i = 0; i < n - 4; i = i + 2) {
          if (a[i] * a[i + 1] < 0) {
            if (a[i] < 0) {
              b[i] = a[i + 1];
              b[i + 1] = -1 * a[i];
            } else {
              b[i] = -1 * a[i + 1];
              b[i + 1] = a[i];
            }
          } else {
            b[i] = -1 * a[i + 1];
            b[i + 1] = a[i];
          }
        }
      }
      if (a[n - 3] < 0) b[n - 3] *= -1;
      if (a[n - 2] < 0) b[n - 2] *= -1;
      b[n - 3] *= abs(a[n - 1]);
      b[n - 2] *= abs(a[n - 1]);
      if (a[n - 1] < 0) {
        b[n - 1] = abs(a[n - 3]) + abs(a[n - 2]);
      } else {
        b[n - 1] = (abs(a[n - 3]) + abs(a[n - 2])) * (-1);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
