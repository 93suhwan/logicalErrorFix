#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int t, n, m, rb, cb, rd, cd, minc, minr;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> rb >> cb >> rd >> cd;
    if (rb > rd)
      minr = n - rb + n - rd;
    else if (rb < rd)
      minr = rd - rb;
    else if (rb == rd)
      minr = 0;
    if (cb > cd)
      minc = m - cb + m - cd;
    else if (cb < cd)
      minc = cd - cb;
    else if (cb == cd)
      minc = 0;
    cout << min(minc, minr) << "\n";
  }
  return 0;
}
