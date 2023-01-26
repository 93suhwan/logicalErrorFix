#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, count = 0;
    cin >> n;
    int m = sqrt(n), s = cbrt(n);
    int ans = m + s - 1;
    cout << ans << "\n";
  }
}
