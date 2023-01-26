#include <bits/stdc++.h>
using namespace std;
void solve() {
  int p1, x1, p2, x2;
  cin >> x1 >> p1 >> x2 >> p2;
  long long tot = pow(10, p1);
  long long tot1 = pow(10, p2);
  if (p1 != 0 && tot % 2 != 0)
    tot = tot + 1;
  else if (p2 != 0 && tot1 % 2 != 0)
    tot1 = tot1 + 1;
  tot = x1 * tot;
  tot1 = x2 * tot1;
  if (tot == tot1)
    cout << "=" << endl;
  else if (tot > tot1)
    cout << ">" << endl;
  else
    cout << "<" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
