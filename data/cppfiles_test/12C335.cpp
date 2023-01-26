#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed;
  cout.precision(10);
  ;
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    string ans = "NO";
    if (n % 2 == 0 and m % 2 == 0) {
      ans = (k & 1 ? "NO" : "YES");
    } else if (m & 1) {
      long long mx = (m - 1) * n / 2;
      if (k <= mx and k % 2 == 0) ans = "YES";
    } else {
      long long mn = m / 2;
      if (k >= mn and (k - mn) % 2 == 0) ans = "YES";
    }
    cout << ans << "\n";
  }
  return 0;
}
