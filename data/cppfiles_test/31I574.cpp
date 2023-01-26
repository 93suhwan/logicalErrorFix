#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
long long a[N], b[N];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, mn = 1e9, sum = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i], mn = min(mn, abs(a[i]));
    for (long long i = 1; i <= n; i++) {
      if (a[i] < 0)
        b[i] = -mn;
      else
        b[i] = mn;
      sum += a[i] * b[i];
    }
    sum = -sum;
    for (long long i = 1; i <= n; i++)
      if (abs(a[i]) == mn) {
        b[i] += sum / mn;
        break;
      }
    for (long long i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";
  }
}
