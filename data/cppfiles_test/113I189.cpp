#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long p1, x1, p2, x2, k2 = 0, k = 0;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  if ((x1 > x2) && (p1 > p2)) {
    cout << ">" << endl;
  }
  if ((x1 < x2) && (p1 < p2)) {
    cout << "<" << endl;
  }
  if ((x1 == x2) && (p1 == p2)) {
    cout << "=" << endl;
  }
  if (x1 * p1 > x2 * p2) {
    cout << ">" << endl;
  }
  if (x1 * p1 < x2 * p2) {
    cout << "<" << endl;
  }
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
