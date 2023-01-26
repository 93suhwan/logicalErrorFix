#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x1, x2, p1, p2;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  x1 *= pow(10, p1);
  x2 *= pow(10, p2);
  if (x1 > x2)
    cout << ">" << endl;
  else if (x1 < x2)
    cout << "<" << endl;
  else
    cout << "=" << endl;
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
