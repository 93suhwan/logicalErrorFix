#include <bits/stdc++.h>
using namespace std;
bool isprime(long long x) {
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long f;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x % 2 == 1) {
        f = i;
      }
      sum += x;
    }
    long long pom = -1;
    if (isprime(sum)) {
      pom = f;
      cout << n - 1 << '\n';
    } else {
      cout << n << '\n';
    }
    for (long long i = 0; i < n; i++) {
      if (i != pom) {
        cout << i + 1 << ' ';
      }
    }
    cout << '\n';
  }
}
