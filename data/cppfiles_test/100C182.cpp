#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int max;
    if (n != 1) {
      sort(a, a + n);
      max = a[1] - a[0];
      for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] > max) max = a[i] - a[i - 1];
      }
      if (a[0] > max) max = a[0];
    }
    if (n == 1) max = a[0];
    cout << max << endl;
  }
  return 0;
}
