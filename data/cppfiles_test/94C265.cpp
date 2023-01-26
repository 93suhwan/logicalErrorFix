#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const long long LMAX = 1e9 + 10;
const long double LDMAX = 1e9 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double PI = acos(-1);
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  long long n, m, t, k;
  long long a, i, j;
  long long ans = 0;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long last = 0;
    k += 1;
    ans = 0;
    for (i = 0; i < n; i++) {
      long long temp = (a[i] - last);
      if (temp == 0) continue;
      long long num = 0;
      m = 1;
      for (j = 0; j < temp; j++) {
        num += 9 * m;
        m *= 10;
      }
      if (k >= num) {
        k -= num;
        for (j = 1; j <= a[i - 1]; j++) num *= 10;
        ans += num;
      } else {
        num = k;
        for (j = 1; j <= a[i - 1]; j++) num *= 10;
        ans += num;
        k = 0;
        break;
      }
      last = a[i];
    }
    if (k > 0) {
      long long num = k;
      for (j = 1; j <= a[n - 1]; j++) num *= 10;
      ans += num;
    }
    cout << ans << '\n';
  }
}
