#include <bits/stdc++.h>
using namespace std;
vector<long long> gaps(1e5 + 1);
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, n;
    cin >> a >> b >> c;
    n = (abs(b - a)) * 2;
    long long ans = ((n / 2) + c);
    if (ans > n) ans = ans % n;
    if (n % 2 != 0 || c > n || a > n || b > n || ans > n || ans == a ||
        ans == b)
      ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
