#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t, k, n, x, a, b, c, q;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    long long int d = abs(a - b);
    x = d * 2;
    if (a > x || b > x || c > x)
      cout << -1 << "\n";
    else {
      k = c + d;
      q = c - d;
      if (k != a && k != b && k <= x)
        cout << k << "\n";
      else if (q != a && q != b && q <= x && q >= 1)
        cout << q << "\n";
      else
        cout << -1 << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
