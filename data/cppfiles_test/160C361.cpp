#include <bits/stdc++.h>
using namespace std;
void Solve() {
  long long n, m, rb, cb;
  long long rd, cd;
  int dr = 1;
  int dc = 1;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  int a, b;
  if (rb <= rd)
    a = rd - rb;
  else
    a = n - rd + n - rb;
  if (cb <= cd)
    b = cd - cb;
  else
    b = m - cd + m - cb;
  cout << min(a, b) << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
