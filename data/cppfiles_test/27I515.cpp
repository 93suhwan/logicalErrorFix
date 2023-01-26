#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n == 1 && m == 0 && k > 0) {
    cout << "YES\n";
    return;
  }
  if (m < n - 1 || m > (n * (n - 1) / 2)) {
    cout << "NO\n";
    return;
  }
  if (m == n - 1 && k > 3 || m == (n * (n - 1) / 2) && k > 2) {
    cout << "YES\n";
    return;
  }
  if (k > 3) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
