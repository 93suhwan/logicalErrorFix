#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, p = 1, c = 0, m = 0;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
      if (a[i] != a[i + 1]) {
        p = 0;
        break;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > m) m = a[i];
    }
    if (p == 1)
      cout << 0 << endl;
    else {
      long long int k = a[n - 1];
      for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= k) {
          c++;
          k = a[i];
        } else if (a[i] == m)
          break;
      }
      cout << c << endl;
    }
  }
}
