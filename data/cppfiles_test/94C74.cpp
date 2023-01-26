#include <bits/stdc++.h>
using namespace std;
long long a[12], ans;
long long n, k, need, sum;
bool have[12];
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    ans = 0, need = 0, sum = 0;
    cin >> n >> k;
    for (long long i = 1; i <= n; ++i) cin >> a[i], a[i] = pow(10, a[i]);
    a[++n] = 1e18;
    for (long long i = 2; i <= n; ++i) {
      if (need + (a[i] - a[i - 1]) / a[i - 1] > k) {
        cout << (k - need + 2) * a[i - 1] - 1 << '\n';
        break;
      }
      need += (a[i] - a[i - 1]) / a[i - 1];
    }
  }
  return 0;
}
