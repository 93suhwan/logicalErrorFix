#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
long long t, n, k;
long long a[N];
int main() {
  cin >> t;
  while (t--) {
    long long ans = -1e18;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long l = max(1ll, n - 2 * k);
    for (int i = l; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        long long tmp = (1ll * (i * j) - (k * (a[i] | a[j])));
        ans = max(ans, 1ll * tmp);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
