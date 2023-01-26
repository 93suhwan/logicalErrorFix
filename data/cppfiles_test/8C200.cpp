#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c1, c2;
    if (n % 3 == 0) {
      c1 = n / 3;
      c2 = c1;
    } else if ((n + 1) % 3 == 0) {
      c2 = (n + 1) / 3;
      c1 = c2 - 1;
    } else {
      c2 = (n - 1) / 3;
      c1 = c2 + 1;
    }
    cout << c1 << " " << c2 << '\n';
  }
}
