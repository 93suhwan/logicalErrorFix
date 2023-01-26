#include <bits/stdc++.h>
using namespace std;
int n, t, a, b;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    if (a + b > n - 2 || abs(a - b) > 1) {
      cout << -1 << endl;
      continue;
    }
    int l, r, f;
    l = 1, r = n, f = (a > b);
    for (int i = 1; i <= n; i++) {
      if (f)
        cout << l++ << " ";
      else
        cout << r-- << " ";
      if (i <= a + b) f ^= 1;
    }
    cout << endl;
  }
}
