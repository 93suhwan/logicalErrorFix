#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  while (test--) {
    long long c, d;
    cin >> c >> d;
    if (c == d) {
      if (c == 0)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    } else {
      if (abs(c - d) % 2)
        cout << -1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
