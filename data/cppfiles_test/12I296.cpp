#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n == 1) {
    if (m == 2 * k) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
  if (k % 2 == 0 || (n * m == 2 * k && n % 2 == 1)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
