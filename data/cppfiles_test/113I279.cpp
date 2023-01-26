#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x1, p1;
  int x2, p2;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  long long z1 = x1 * pow(10, p1);
  long long z2 = x2 * pow(10, p2);
  if (z1 > z2)
    cout << ">\n";
  else if (z1 < z2)
    cout << "<\n";
  else
    cout << "=\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
