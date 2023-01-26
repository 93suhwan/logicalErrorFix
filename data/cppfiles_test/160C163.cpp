#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int a = 0; a < t; a++) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int ans = 0;
    int dr = 1;
    int cr = 1;
    while (rb != rd and cb != cd) {
      ans++;
      if (dr + rb > n or ((dr + rb) <= 0)) {
        dr = -dr;
      }
      if (cb + cr > m or ((cb + cr) <= 0)) {
        cr = -cr;
      }
      rb += dr;
      cb += cr;
    }
    cout << ans << "\n";
  }
  return 0;
}
