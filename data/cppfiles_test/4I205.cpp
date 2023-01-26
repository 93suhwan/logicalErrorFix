#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long p;
  cin >> p;
  if (p % 2 == 1) {
    cout << p - 1 << " " << 2 << endl;
  }
  if (p % 2 == 0) {
    cout << 2 << " " << p << endl;
  }
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
