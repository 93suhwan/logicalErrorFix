#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  k -= 2LL;
  if (n - 1 > m) {
    cout << "NO\n";
    return;
  }
  if (m > (n * (n - 1)) / 2LL) {
    cout << "NO\n";
    return;
  }
  if (m == (n * (n - 1)) / 2LL) {
    if (k >= 1) {
      cout << "YES\n";
      return;
    }
    if (k == 0 && n == 1) {
      cout << "YES\n";
      return;
    }
    cout << "NO\n";
    return;
  }
  if (k >= 2) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
