#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  for (cin >> t; t; t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int len = n;
    while (len > 1) {
      if (a[n - len] > a[n - len + 1] - a[n - len] && a[n - len] > 0) break;
      for (int i = n - len + 1; i < n; i++) a[i] -= a[n - len];
      len--;
    }
    cout << a[n - len] << endl;
  }
  return 0;
}
