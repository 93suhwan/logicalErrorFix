#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int main() {
  int t, n, m, rb, cb, rd, cd;
  cin >> t;
  while (t--) {
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dr = 1, dc = 1;
    int ans = 0;
    while (rb != rd && cb != cd) {
      if (rb >= n || rb <= 0) {
        dr *= -1;
      }
      if (cb >= m || cb <= 0) {
        dc *= -1;
      }
      rb += dr;
      cb += dc;
      ans++;
    }
    cout << ans << "\n";
  }
}
