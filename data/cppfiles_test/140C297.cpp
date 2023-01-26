#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  cout << floor(sqrt(n)) + floor(cbrt(n)) - floor(sqrt(cbrt(n)));
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
