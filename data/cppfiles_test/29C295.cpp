#include <bits/stdc++.h>
using namespace std;
namespace std {}
long long t, n, m;
long long a[(long long)1e3 + 10];
long long ans = 0;
long long sum = 0;
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    sum = 0;
    long long zero = 0, one = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == 0)
        zero++;
      else if (a[i] == 1)
        one++;
    }
    ans = pow(2, zero) * one;
    cout << ans << '\n';
  }
}
