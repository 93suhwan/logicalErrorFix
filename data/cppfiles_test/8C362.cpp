#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int d = n % 3;
    if (d == 0) {
      cout << n / 3 << " " << n / 3 << "\n";
    } else if (d == 1) {
      cout << (n / 3) + 1 << " " << n / 3 << "\n";
    } else {
      cout << (n / 3) << " " << (n / 3) + 1 << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
