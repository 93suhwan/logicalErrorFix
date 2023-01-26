#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long total = n * m / 2;
  if (n % 2 == 0 && m % 2 == 0 && k % 2 == 0) {
    cout << "YES\n";
    return;
  }
  if (n % 2 == 1 && k % 2 == (m / 2) % 2 && k <= total && k >= m / 2) {
    cout << "YES\n";
    return;
  }
  if (m % 2 == 1 && k % 2 == 0 && k <= total - n / 2) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
