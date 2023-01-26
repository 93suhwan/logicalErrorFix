#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
void faster() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long T, n;
long long a[maxn], b[maxn];
signed main() {
  faster();
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0) {
      for (long long i = 1; i <= n; i += 2) b[i] = a[i + 1], b[i + 1] = -a[i];
      for (long long i = 1; i <= n; i++) cout << b[i] << " ";
    } else {
      for (long long i = 1; i <= n - 3; i += 2)
        b[i] = a[i + 1], b[i + 1] = -a[i];
      b[n - 2] = a[n - 1] + a[n];
      b[n - 1] = -a[n - 2];
      b[n] = -a[n - 2];
      for (long long i = 1; i <= n; i++) cout << b[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
