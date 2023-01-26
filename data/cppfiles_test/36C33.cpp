#include <bits/stdc++.h>
using namespace std;
bool cp(int n) {
  int i, j = sqrt(n);
  for (i = 2; i <= j; i++) {
    if (n % i == 0) return true;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, sum = 0, j;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (cp(sum)) {
      cout << n << endl;
      for (i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      for (i = 0; i < n; i++) {
        if (cp(sum - a[i])) {
          cout << n - 1 << endl;
          for (j = 1; j <= n; j++) {
            if (j != i + 1) cout << j << " ";
          }
          cout << endl;
          break;
        }
      }
    }
  }
  return 0;
}
