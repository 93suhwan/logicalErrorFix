#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int min = 100000000;
    while (a[n - 1] - a[0] < min) {
      min = a[n - 1] - a[0];
      for (int i = 0; i < n / 2; i++) {
        int m = a[n - 1] - a[0];
        a[0] = a[0] + m / 2;
        a[n - 1] = a[n - 1] - (m - m / 2);
      }
      sort(a, a + n);
    }
    cout << min << endl;
  }
  return 0;
}
