#include <bits/stdc++.h>
using namespace std;
void solve(long long n, long long m, long long k) {
  if (n % 2 == 1 && ((2 * k) / m) % 2 == 1 && (2 * k % m) % 2 == 0) {
    cout << "YES"
         << "\n";
  } else if (n % 2 == 0 && k % 2 == 0) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    solve(n, m, k);
  }
}
