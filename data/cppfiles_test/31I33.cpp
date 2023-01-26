#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0) {
      for (long long int i = 0; i < n; i++) {
        if (i % 2)
          cout << -a[i - 1] << " ";
        else
          cout << a[i + 1] << " ";
      }
    } else {
      for (long long int i = 0; i < n - 3; i++) {
        if (i % 2)
          cout << -a[i - 1] << " ";
        else
          cout << a[i + 1] << " ";
      }
      long long int x = a[n - 3], y = a[n - 2], z = a[n - 1];
      if (x + y != 0)
        cout << -z << " " << -z << " " << x + y;
      else if (z + y != 0)
        cout << -x << " " << -x << " " << z + y;
      else if (x + z != 0)
        cout << -y << " " << -y << " " << x + z;
    }
    cout << endl;
  }
  return 0;
}
