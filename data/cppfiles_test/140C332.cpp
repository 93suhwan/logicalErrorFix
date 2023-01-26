#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, count = 0;
    cin >> n;
    int m = sqrt(n), s = cbrt(n), k = cbrt(m);
    int ans = m + s - k;
    cout << ans << "\n";
  }
}
