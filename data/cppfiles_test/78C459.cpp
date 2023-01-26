#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, l, r, a, b;
  cin >> t;
  while (t-- > 0) {
    cin >> l >> r;
    b = max(l, r / 2 + 1);
    a = r;
    cout << (a % b) << "\n";
  }
  return 0;
}
