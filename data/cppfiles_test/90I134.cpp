#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000000000000000000;
long long mod = 1000000000;
long double pi = 3.141592653589793238;
void pls() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 3e5 + 2;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x == y) {
      cout << x << endl;
    } else if (y > x) {
      cout << (x + y) / 2 << endl;
    } else {
      cout << (x + y) << endl;
    }
  }
}
int main() {
  pls();
  solve();
  return 0;
}
