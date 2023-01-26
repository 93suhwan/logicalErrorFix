#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, i, j, k, x, cnt = 0;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    x = a[n - 1];
    j = 0;
    m = *max_element(a, a + n);
    for (i = n - 1; i >= 0; i--) {
      x = a[i];
      if (x == m) {
        break;
      }
      if (x > j && x <= m) {
        cnt++;
        j = x;
      } else {
        if (x > j) {
          j = x;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
