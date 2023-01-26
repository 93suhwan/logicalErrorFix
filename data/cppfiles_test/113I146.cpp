#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long x1, p1;
  cin >> x1 >> p1;
  long long x2, p2;
  cin >> x2 >> p2;
  if ((x1) * (pow(10, p1)) == (x2 * (pow(10, p2)))) {
    cout << "=" << endl;
  }
  if (x1 * (pow(10, p1)) > x2 * (pow(10, p2))) {
    cout << ">" << endl;
  }
  if (x1 * (pow(10, p1)) < x2 * (pow(10, p2))) {
    cout << "<" << endl;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
