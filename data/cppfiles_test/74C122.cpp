#include <bits/stdc++.h>
using namespace std;
int isSorted(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  for (int l = 1; l <= t; l++) {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 1) {
      int x = max(a, b) - (a + b + 1) / 2;
      if (x % 2 != (a + b - x) % 2) {
        cout << 2 * (min(a, b) + 1) << "\n";
        for (int i = 1; i <= 2 * (min(a, b) + 1); i++) {
          cout << x++ << " ";
        }
      } else {
        int x = max(a, b) - (a + b + 1) / 2;
        while (x <= a + b - (max(a, b) - (a + b + 1) / 2)) {
          cout << x << " ";
          x += 2;
        }
      }
    } else {
      cout << min(a, b) + 1 << "\n";
      int x = (a + b) / 2 - min(a, b);
      for (int i = 1; i <= min(a, b) + 1; i++) {
        cout << x << " ";
        x += 2;
      }
    }
    cout << "\n";
  }
  return 0;
}
