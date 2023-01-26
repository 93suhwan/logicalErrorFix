#include <bits/stdc++.h>
using namespace std;
void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}
int main() {
  init();
  int t;
  cin >> t;
  int n, m, rb, cb, rd, cd;
  while (t--) {
    int ans = 0;
    int fin_ans = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int walkr = 1, walkc = 1;
    while (rb != rd && cb != cd) {
      if (rb + walkr > n || rb + walkr < 1) {
        walkr *= -1;
      }
      if (cb + walkc > m || cb + walkc < 1) {
        walkc *= -1;
      }
      rb += walkr;
      cb += walkc;
      ans++;
    }
    cout << ans << endl;
  }
}
