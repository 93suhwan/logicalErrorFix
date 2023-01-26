#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    string ans;
    if (n % 2 == 1) {
      int x = m / 2;
      if (k < x) {
        ans = "NO";
      } else {
        k = k - x;
        if (k % 2)
          ans = "NO";
        else
          ans = "YES";
      }
    } else if (m % 2 == 1) {
      m = m - 1;
      int x = n * m / 2;
      if (k % 2 == 0 && k <= x)
        ans = "YES";
      else
        ans = "NO";
    } else {
      if (k % 2 == 0)
        ans = "YES";
      else
        ans = "NO";
    }
    cout << ans << '\n';
  }
  return 0;
}
