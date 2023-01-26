#include <bits/stdc++.h>
long long pri(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
using namespace std;
signed main() {
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    long long a[n];
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (pri(sum) == 0) {
      cout << n << '\n';
      for (long long i = 1; i <= n; i++) cout << i << " ";
    } else {
      for (long long i = 0; i < n; i++) {
        if (pri(sum - a[i]) == 0) {
          cout << n - 1 << "\n";
          for (long long j = 0; j < n; j++) {
            if (i != j) cout << j + 1 << " ";
          }
          break;
        }
      }
    }
    cout << '\n';
  }
}
