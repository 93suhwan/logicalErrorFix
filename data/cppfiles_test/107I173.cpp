#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c, b;
    cin >> n >> c >> b;
    int a[n];
    for (int i = 0; i < n; i++) {
      a[i] = i + 1;
    }
    if (n - 2 < c + b || abs(c - b) > 1) {
      cout << "-1";
    } else {
      if (c == b) {
        for (int i = 1; i <= 2 * c; i = i + 2) {
          swap(a[i], a[i + 1]);
        }
      } else if (c < b) {
        for (int i = 0; i <= 2 * c; i = i + 2) {
          swap(a[i], a[i + 1]);
        }
      } else if (c > b) {
        int j = c;
        for (int i = n - 1; j > 0; i = i - 2) {
          swap(a[i], a[i + 1]);
          j--;
        }
      }
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
