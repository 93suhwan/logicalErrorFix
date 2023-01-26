#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    long long ans = 0, dr = 1, dr2 = 1;
    while (true) {
      if (rb == rd || cb == cd) {
        break;
      }
      if (rb + dr > n || rb + dr < 1) {
        dr *= -1;
      }
      if (cb + dr2 > m || cb + dr2 < 1) {
        dr2 *= -1;
      }
      rb += dr;
      cb += dr2;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
