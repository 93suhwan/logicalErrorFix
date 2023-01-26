#include <bits/stdc++.h>
using namespace std;
const long long N = 110;
long long a[N];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long res = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      if (i < a[i]) res = max(res, a[i] - i);
    }
    cout << res << endl;
  }
  return 0;
}
