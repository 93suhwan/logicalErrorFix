#include <bits/stdc++.h>
using namespace std;
const int N = 2000006;
int n, m;
int a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int rb, cb, rd, cd;
    cin >> rb >> cb >> rd >> cd;
    int dr = 1, dc = 1;
    int ans = 0;
    for (int i = 0; i <= 400; i++) {
      if (rb == rd || cd == cb) {
        ans = i;
        break;
      }
      rb += dr;
      cb += dc;
      if (rb > n) {
        rb = n - 1;
        dr = -1;
      }
      if (rb < 1) {
        rb = 2;
        dr = 1;
      }
      if (cb > m) {
        cb = m - 1;
        dc = -1;
      }
      if (cb < 1) {
        cb = 2;
        dc = 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
