#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e4 + 10;
const long long IM = 1e15 + 37;
const double PI = 3.1415926535897932384;
long long isprime(long long N) {
  if (N < 2 || (!(N & 1) && N != 2)) return 0;
  for (long long i = 3; i * i <= N; i += 2) {
    if (!(N % i)) return 0;
  }
  return 1;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long g = 1;
    long long f = 0;
    for (long long i = 1; i <= n; i++) {
      if (isprime(i + 1)) {
        g = g * (i + 1);
      }
      if ((a[i] % g) == 0) {
        f = 1;
        break;
      }
    }
    if (f == 1) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
}
