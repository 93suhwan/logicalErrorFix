#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    if (c == d)
      cout << 1;
    else if ((c + d) % 2 == 0)
      cout << 2;
    else
      cout << -1;
    cout << "\n";
  }
}
