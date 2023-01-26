#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long i = 1;
    for (i = 1; i * i <= k; i++) {
      ;
    }
    i--;
    k -= i * i;
    if (k == 0) {
      cout << i << " " << 1 << endl;
    } else if (k <= i + 1) {
      cout << k << " " << i + 1 << endl;
    } else {
      k -= (i + 1);
      cout << i + 1 << " " << i + 1 - k << endl;
    }
  }
}
