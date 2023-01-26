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
    cout << -a[2] << " " << -a[2] << " " << a[1] + a[0] << " ";
    for (long long i = 3; i < n; i += 2) {
      cout << -a[i + 1] << " " << a[i] << " ";
    }
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
