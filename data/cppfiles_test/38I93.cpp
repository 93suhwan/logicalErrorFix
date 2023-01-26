#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
using namespace std;
int main() {
  int t;
  cin >> t;
  long long p[3] = {6, 8, 10};
  long long c[3] = {15, 20, 25};
  while (t--) {
    long long n;
    cin >> n;
    long long ans = LONG_LONG_MAX;
    for (int i = 0; i < 3; i++) {
      if (n % p[i] == 0) {
        ans = min(ans, (long long)(n / p[i]) * c[i]);
      } else {
        ans = min(ans, ((long long)(n / p[i]) + 1) * c[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
