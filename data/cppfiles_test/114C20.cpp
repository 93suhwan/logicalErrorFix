#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000007;
const long long INF = 1000000000000000000;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(numeric_limits<long double>::max_digits10);
  long long t;
  cin >> t;
  for (long long tno = 1; tno <= t; tno++) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long t1 = 0; t1 < n; t1++) {
      cin >> a[t1];
    }
    sort(a, a + n);
    for (long long t1 = 0; t1 < (n / 2); t1++) {
      cout << a[t1 + 1] << " " << a[0] << '\n';
    }
  }
  return 0;
}
