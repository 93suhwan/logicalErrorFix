#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long int sum = 0;
    for (long long int i = 0; i < n - 2 * k; i++) sum += a[i];
    for (long long int i = n - 2 * k; i < n - k; i++) sum += a[i] / a[i + k];
    cout << sum;
    cout << "\n";
  }
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
