#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t, n, d;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long num = 0;
    for (long long i = n - 1; i >= 0; i--) {
      num += (a[i] << (n - 1 - i));
    }
    long long cnt = 0;
    long long pr = num - 1;
    while (num != pr) {
      pr = num;
      long long b = ((num - ((num >> d) << d)) << (n - d));
      long long a = (num >> d);
      num = (num & (b + a));
      cnt++;
    }
    cnt--;
    if (num != 0) {
      cout << -1 << "\n";
      continue;
    }
    cout << cnt << "\n";
  }
}
