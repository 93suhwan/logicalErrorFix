#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long f = min(a, b);
    long long s = max(a, b);
    long long n = 2 * s - 2 * f;
    if (a > n || b > n || c > n || n % 2 == 1) {
      cout << -1 << endl;
      continue;
    } else {
      long long ans = c + n / 2;
      if (ans > n) {
        ans = ans - n;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
