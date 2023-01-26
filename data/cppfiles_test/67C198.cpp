#include <bits/stdc++.h>
using namespace std;
const int oo = 1e5 + 7;
const int inf = 0x3f3f3f3f;
long long a, b, c;
signed main() {
  if (ifstream(".inp")) {
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    long long n = (abs(a - b)) * 2;
    if (a > n || b > n || c > n)
      cout << -1 << '\n';
    else if (c > n / 2) {
      long long d = c - n / 2;
      if (d != a && d != b && d > 0 && d <= n)
        cout << d << '\n';
      else
        cout << -1 << '\n';
    } else {
      long long d = c + n / 2;
      if (d != a && d != b && d > 0 && d <= n)
        cout << d << '\n';
      else
        cout << -1 << '\n';
    }
  }
  return 0;
}
