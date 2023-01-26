#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void Solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  --rb, --cb, --rd, --cd;
  int dr = 1, dc = 1, ans = 0;
  while (rb != rd && cb != cd) {
    if (dr == 1 && rb == n - 1) {
      dr = -1;
    }
    if (dr == -1 && rb == 0) {
      dr = 1;
    }
    if (dc == 1 && cb == m - 1) {
      dc = -1;
    }
    if (dc == -1 && dc == 0) {
      dc = 1;
    }
    rb += dr;
    cb += dc;
    ans++;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
}
