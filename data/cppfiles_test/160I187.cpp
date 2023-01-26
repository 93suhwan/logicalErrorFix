#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    int count = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    if (rb == rd || cb == cd) {
      count = 0;
    } else if (rb < rd && cb < cd) {
      count = min(rd - rb, cd - cb);
    } else if (rb > rd && cb < cd) {
      count = cd - cb;
    } else if (rb < rd && cb > cd) {
      count = rd - rb;
    } else if (rb > rd && cb > cd) {
      count = max(n, m);
    }
    cout << count << endl;
  }
  return 0;
}
