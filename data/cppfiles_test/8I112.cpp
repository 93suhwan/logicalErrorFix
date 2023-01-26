#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t, ans = 1;
  cin >> t;
  while (t--) {
    long long a;
    cin >> a;
    cout << ((a % 3) ? (a / 3) + 1 : a / 3) << ' ' << a / 3 << '\n';
  }
}
