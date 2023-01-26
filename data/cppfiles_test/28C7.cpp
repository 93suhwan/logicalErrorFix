#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a, b, c, n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a >> b >> c;
    if ((a + b * 2 + c * 3) % 2 == 0) cout << 0;
    cout << endl;
    if ((a + b * 2 + c * 3) % 2 == 1) cout << 1;
    cout << endl;
  }
}
