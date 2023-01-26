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
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (!(n % 2)) {
      for (long long i = 1; i <= n; i += 2)
        cout << -a[i + 1] << " " << a[i] << " ";
      cout << endl;
      continue;
    }
    if (a[2] + a[3] != 0) {
      cout << a[2] + a[3] << " " << -a[1] << " " << -a[1] << " ";
      for (long long i = 4; i <= n; i += 2)
        cout << a[i + 1] << " " << -a[i] << " ";
      cout << endl;
      continue;
    }
    cout << a[2] - a[3] << " " << -a[1] << " " << a[1] << " ";
    for (long long i = 4; i <= n; i += 2)
      cout << a[i + 1] << " " << -a[i] << " ";
    cout << endl;
  }
}
