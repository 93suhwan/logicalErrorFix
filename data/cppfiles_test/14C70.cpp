#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t = 0;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    long long n = 0;
    cin >> n;
    vector<long long> v(n, 0);
    vector<long long> u(n, 0);
    long long a[n + 1][3];
    for (long long j = 0; j < n; ++j) {
      cin >> v[j];
      u[j] = v[j];
    }
    sort(u.begin(), u.end());
    long long count = 0;
    for (long long j = 0; j < n; ++j) {
      for (long long k = 0; k < n - j; ++k) {
        long long y = 0;
        if (u[n - j - 1] == v[k] && k != (n - j - 1)) {
          a[count][0] = k + 1;
          a[count][1] = n - j;
          a[count][2] = 1;
          assert(a[count][0] <= a[count][1]);
          for (long long l = k + 1; l < n - j; ++l) {
            swap(v[l - 1], v[l]);
          }
          y = 1;
          count++;
          break;
        }
        if (y == 1) {
          break;
        }
      }
      long long x = 0;
      for (long long k = 0; k < n; ++k) {
        if (u[k] != v[k]) {
          x = 1;
          break;
        }
      }
      if (x == 0) {
        break;
      }
    }
    cout << count << endl;
    for (long long k = 0; k < count; k++) {
      cout << a[k][0] << " " << a[k][1] << " " << a[k][2] << endl;
    }
  }
  return 0;
}
