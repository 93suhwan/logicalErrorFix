#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n, n1;
    cin >> x >> n;
    n1 = n / 4;
    n1 *= 4;
    long long st = 0;
    for (long long i = n1 + 1; i <= n; i++) {
      if (i - n1 == 1 || i - n1 == 4)
        st += i;
      else
        st -= i;
    }
    long long ans;
    if (x % 2)
      ans = x + st;
    else
      ans = x - st;
    cout << ans << "\n";
  }
  return 0;
}
