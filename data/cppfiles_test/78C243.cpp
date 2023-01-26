#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int l1, r1;
    cin >> l1 >> r1;
    long long int val1 = l1;
    if ((r1 / 2) + 1 > l1) {
      val1 = (r1 / 2) + 1;
    }
    cout << r1 % val1 << endl;
  }
  return 0;
}
