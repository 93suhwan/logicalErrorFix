#include <bits/stdc++.h>
using namespace std;
bool prime(long long x) {
  if (x == 1) return false;
  if (x == 2) return true;
  for (long long i = 3; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
void testcase() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long p = 1;
  for (long long i = 1; i <= n; i++) {
    if (p > 1e18 / (i + 1)) break;
    if (prime(i + 1)) p *= i + 1;
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
