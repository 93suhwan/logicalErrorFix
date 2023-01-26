#include <bits/stdc++.h>
using namespace std;
bool findPrime(long long n) {
  if (n == 1) return 0;
  if (n == 2 || n == 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  long long i = 5, k = 2;
  while (i * i <= n) {
    if (n % i == 0) return 0;
    i = i + k;
    k = 6 - k;
  }
  return 1;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (!findPrime(sum)) {
      cout << n << endl;
      for (long long i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << endl;
    } else {
      long long index = -1;
      for (long long i = 0; i < n; i++) {
        long long diff = sum - a[i];
        if (!findPrime(diff)) {
          index = i;
          break;
        }
      }
      cout << n - 1 << endl;
      for (long long i = 0; i < n; i++) {
        if (i == index) {
          continue;
        }
        cout << i + 1 << " ";
      }
      cout << endl;
    }
  }
}
