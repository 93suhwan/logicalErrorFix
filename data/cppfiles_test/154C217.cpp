#include <bits/stdc++.h>
using namespace ::std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if ((a == b && c % 2 != 1) || (b == c && a % 2 != 1) ||
      (a == c && b % 2 != 1) || a == b + c || b == a + c || c == a + b)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
