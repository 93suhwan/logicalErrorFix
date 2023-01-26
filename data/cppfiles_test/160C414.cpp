#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int a = rb <= rd ? rd - rb : 2 * n - rb - rd;
    int b = cb <= cd ? cd - cb : 2 * m - cb - cd;
    cout << min(a, b) << '\n';
  }
  return 0;
}
