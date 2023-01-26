#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long cnt = 0;
    long long j = 1;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      if (x > j) {
        long long k = j;
        cnt += (x - k);
        j += (x - k);
      }
      j++;
    }
    cout << cnt << endl;
  }
}
