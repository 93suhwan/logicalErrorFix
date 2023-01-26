#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n & 1) {
    for (long long i = 0; i < n - 3; i += 2) {
      cout << -a[i + 1] << " " << -a[i] << " ";
    }
    cout << -a[n - 1] * a[n - 2] << " ";
    cout << -a[n - 1] * a[n - 3] << " ";
    cout << 2 * a[n - 2] * a[n - 3] << " ";
  } else {
    for (long long i = 0; i < n; i += 2) {
      cout << -a[i + 1] << " " << a[i] << " ";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solve();
    cout << "\n";
  }
  return 0;
}
