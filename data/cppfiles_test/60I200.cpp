#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, f1 = 0, f2 = 0, x, z;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0)
        f1 = 1;
      else
        f2 = 1;
    }
    sort(a, a + n);
    if (f1 && f2) {
      for (long long i = 0; i < n; i++) {
        if (f1 && a[i] % 2 == 0)
          x = a[i], f1 = 0;
        else if (f2 && a[i] % 2 != 0)
          z = a[i], f2 = 0;
      }
      x = x & z;
      cout << x << "\n";
    } else
      cout << a[0] << "\n";
  }
  return 0;
}
