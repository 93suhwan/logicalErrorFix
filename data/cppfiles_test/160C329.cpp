#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    int count = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    if (rb <= rd && cb <= cd)
      cout << min(rd - rb, cd - cb) << endl;
    else if (rb <= rd && cb > cd)
      cout << min(rd - rb, 2 * m - cb - cd) << endl;
    else if (cb <= cd && rb > rd)
      cout << min(cd - cb, 2 * n - rb - rd) << endl;
    else
      cout << min(2 * n - rb - rd, 2 * m - cb - cd) << endl;
  }
  return 0;
}
