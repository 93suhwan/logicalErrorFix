#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long double PI = 3.141592653589793;
const long long maxn = 100005;
long long x, y, z, n, k;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long tot = n * m / 2;
  long long v = tot - k;
  long long h = k;
  if (n % 2) {
    swap(n, m);
    swap(h, v);
  }
  if (m % 2) v -= n / 2;
  if (v >= 0 && (v % 2 == 0) && (h % 2 == 0)) {
    cout << "YES"
         << "\n";
    return;
  }
  cout << "NO"
       << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(15) << fixed;
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
