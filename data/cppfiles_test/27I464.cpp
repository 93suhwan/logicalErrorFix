#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n == 1) {
    if (k <= 1) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
    return;
  }
  if (m == n * (n - 1) / 2) {
    if (k <= 2) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
    return;
  }
  if (m <= n * (n - 1) / 2 && m >= n - 1) {
    if (k <= 3) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
    return;
  }
  cout << "NO" << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
