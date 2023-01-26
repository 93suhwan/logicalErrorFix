#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int solve() {
  int n;
  cin >> n;
  switch (n % 3) {
    case 0:
      cout << n / 3 << ' ' << n / 3;
      break;
    case 1:
      cout << n / 3 + 1 << ' ' << n / 3;
      break;
    default:
      cout << n / 3 << ' ' << n / 3 + 1;
  }
  cout << '\n';
  return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
