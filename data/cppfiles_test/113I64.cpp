#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long p1, x1, p2, x2, k2 = 0, k = 0;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  k = x1 * pow(10, p1);
  k2 = x2 * pow(10, p2);
  if (k < k2) {
    cout << "<" << endl;
  } else {
    if (k = k2) {
      cout << "=" << endl;
    } else {
      cout << ">" << endl;
    }
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
