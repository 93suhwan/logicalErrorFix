#include <bits/stdc++.h>
using namespace std;
const long long N = 100 + 5;
long long n;
long long t, k;
long long a[N];
signed main() {
  cin >> t;
  long long sum = 0;
  while (t--) {
    sum = 0;
    cin >> n >> k;
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long r = n - 1;
    long long l = r - k;
    for (long long j = 0; j < k; j++) {
      sum += (a[l - j] / a[r - j]);
      a[r - j] = 0, a[l - j] = 0;
    }
    for (long long i = 0; i < n; i++) sum += a[i];
    cout << sum << endl;
  }
  return 0;
}
