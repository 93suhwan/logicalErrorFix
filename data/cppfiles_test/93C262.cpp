#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    long long n, k;
    cin >> n >> k;
    if (n == 1)
      cout << 0 << endl;
    else if (k == 1)
      cout << n - 1 << endl;
    else {
      long long bef = 0;
      long long t = 1;
      while (t <= k and t <= n) {
        t *= 2;
        bef++;
      }
      n = n - t;
      long long ans = (ceil(n / (float)k)) + bef;
      cout << ans << endl;
    }
  }
}
