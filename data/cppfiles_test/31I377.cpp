#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n + 1];
    for (long long i = 0; i < n; ++i) cin >> a[i];
    long long k = 0;
    if (n % 2) k = 3;
    for (long long i = 0; i < n - k; i += 2)
      cout << -a[i + 1] << " " << a[i] << " ";
    if (n % 2) {
      if (a[n - 1] - a[n - 2] < a[n - 1] + a[n - 2])
        cout << a[n - 1] - a[n - 2] << " " << a[n - 3] << " " << -a[n - 3]
             << endl;
      else
        cout << a[n - 1] + a[n - 2] << " " << -a[n - 3] << " " << -a[n - 3]
             << endl;
    }
  }
}
