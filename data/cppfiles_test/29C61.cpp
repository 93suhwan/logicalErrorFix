#include <bits/stdc++.h>
using namespace std;
long long qmi(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
signed main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long zero = 0, one = 0;
    for (long long i = 1, a; i <= n; i++) {
      cin >> a;
      if (a == 0)
        zero++;
      else if (a == 1)
        one++;
    }
    if (!one)
      puts("0");
    else {
      cout << one * qmi(2, zero) << endl;
    }
  }
  return 0;
}
