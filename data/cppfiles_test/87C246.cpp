#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int x = 0;
    for (long long int i = 0; i < n; i++) {
      if (a[i] <= (i + 1 + x)) continue;
      x += (a[i] - (i + 1 + x));
    }
    cout << x << endl;
  }
  return 0;
}
