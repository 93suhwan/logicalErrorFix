#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, k, ans, n1, d;
  cin >> t;
  while (t > 0) {
    t--;
    ans = 0;
    cin >> n >> k;
    n1 = 1;
    d = 2;
    while (n1 < n) {
      if (n1 <= k) {
        n1 *= 2;
        ans++;
      } else {
        if (((n - n1) / k) * k == (n - n1)) {
          ans += (n - n1) / k;
          n1 = n;
        } else {
          ans += (n - n1) / k + 1;
          n1 = n;
        }
      }
    }
    cout << ans << endl;
  }
}
