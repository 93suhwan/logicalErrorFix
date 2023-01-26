#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
void solve() {
  int n;
  cin >> n;
  cout << n / 10 + (n % 10 == 9) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
