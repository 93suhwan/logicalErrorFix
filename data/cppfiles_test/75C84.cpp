#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long TC = 1;
  while (TC--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long lcnt = 1, rcnt = 1;
    for (long long i = 1; i < n; i++) {
      if (a[i] > a[i - 1])
        lcnt++;
      else
        break;
    }
    for (long long i = n - 1 - 1; i >= 0; i--) {
      if (a[i] > a[i + 1])
        rcnt++;
      else
        break;
    }
    if ((a[0] >= a[n - 1] && lcnt % 2) || (a[0] <= a[n - 1] && rcnt % 2)) {
      cout << "Alice\n";
      continue;
    } else if (lcnt % 2 == 0 && rcnt % 2 == 0) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
  }
  return 0;
}
