#include <bits/stdc++.h>
using namespace std;
void TEST_CASE() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long mn = n - 1;
  long long mx = (n * (n - 1)) / 2;
  if (m < mn || m > mx) {
    cout << "NO"
         << "\n";
    return;
  }
  long long d = 3000000000000000000;
  if (n <= 2) {
    d = n - 1;
  } else {
    if (m == mx) {
      d = 1;
    } else {
      d = 2;
    }
  }
  if (d < k - 1) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
signed main() {
  freopen("Error.txt", "w", stderr);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    TEST_CASE();
  }
  return 0;
}
