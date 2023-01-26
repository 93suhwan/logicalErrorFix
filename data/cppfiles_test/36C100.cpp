#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / (gcd(a, b));
}
long long int prime(long long int n) {
  long long int i;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  if (n <= 1) return 0;
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) sum += a[i];
    if (!prime(sum)) {
      cout << n << "\n";
      for (long long int i = 0; i < n; i++) cout << i + 1 << " ";
      cout << "\n";
    } else {
      long long int f;
      for (long long int i = 0; i < n; i++) {
        if (!prime((sum - a[i]))) {
          f = i + 1;
          break;
        }
      }
      cout << n - 1 << "\n";
      for (long long int i = 0; i < n; i++) {
        if (i != f - 1) cout << i + 1 << " ";
      }
      cout << "\n";
    }
  }
}
