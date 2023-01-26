#include <bits/stdc++.h>
using namespace std;
void testcase() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long p = 1;
  for (long long i = 1; i <= n; i++) {
    p *= i + 1;
    if (p > 1e9) break;
    if (a[i - 1] % p == 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) testcase();
  exit(EXIT_SUCCESS);
}
