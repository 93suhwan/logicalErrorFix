#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
void solve() {
  long long x, n;
  cin >> x >> n;
  if (x & 1) {
    long long y = n % 4;
    if (y == 0) cout << x << endl;
    if (y == 1) cout << x + n << endl;
    if (y == 2) cout << x + 1 << endl;
    if (y == 3) cout << x - 1 - n << endl;
  } else {
    long long y = n % 4;
    if (y == 0) cout << x << endl;
    if (y == 1) cout << x - n << endl;
    if (y == 2) cout << x + 1 << endl;
    if (y == 3) cout << x + n + 1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
