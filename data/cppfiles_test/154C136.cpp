#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long LINF = 1e18;
void solve() {
  array<long long, 3> t;
  cin >> t[0] >> t[1] >> t[2];
  sort(t.begin(), t.end());
  if (t[2] == t[0] + t[1] || (t[0] == t[1] && t[2] % 2 == 0) ||
      (t[1] == t[2] && t[0] % 2 == 0)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
long long main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
}
