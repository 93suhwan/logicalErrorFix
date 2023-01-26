#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    if (x % 2 == 1 || x % 2 == -1) {
      long long num = n / 4 * 4;
      long long ans = 0;
      for (long long i = num + 1; i <= n; i++) {
        if (ans % 2)
          ans -= i;
        else
          ans += i;
      }
      cout << x + ans << endl;
    } else {
      long long num = n / 4 * 4;
      long long ans = 0;
      for (long long i = num + 1; i <= n; i++) {
        if (ans % 2)
          ans += i;
        else
          ans -= i;
      }
      cout << x + ans << endl;
    }
  }
}
