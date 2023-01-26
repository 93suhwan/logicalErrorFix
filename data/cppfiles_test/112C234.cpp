#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    cin >> a >> b >> c >> m;
    if (a + b + c - 3 < m)
      cout << "NO";
    else {
      long long k = max(a, max(b, c));
      long long s = a + b + c - k;
      if (m < k - 1 - s)
        cout << "NO";
      else
        cout << "YES";
    }
    cout << endl;
  }
}
