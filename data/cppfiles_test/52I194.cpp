#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0;
    long long p = pow(10, 9) + 7;
    cin >> n >> k;
    long long m = 0;
    while (pow(2, m + 1) <= k) {
      m++;
    }
    for (int i = m; i >= 0; i--) {
      if (k >= pow(2, i)) {
        k = k - pow(2, i);
        long long r = pow(n, i);
        ans = (ans + r) % p;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
