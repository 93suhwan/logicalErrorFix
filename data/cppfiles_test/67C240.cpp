#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
      long long int t = a;
      a = b;
      b = t;
    }
    if (2 * a > b) {
      cout << -1 << endl;
    } else {
      long long int ans = (c + (b - a)) % (2 * (b - a));
      if (ans == 0) {
        ans = 2 * (b - a);
      }
      if (c > 2 * (b - a))
        cout << -1 << endl;
      else
        cout << ans << endl;
    }
  }
}
