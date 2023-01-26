#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long dia = max(a, b) - min(a, b);
  long long circle = 2 * dia;
  if (max(a, b) > circle)
    cout << -1 << "\n";
  else {
    long long opp = (dia + c) % (circle);
    if (opp != a && opp != b && opp != c) {
      opp == 0 ? cout << circle << "\n" : cout << opp << "\n";
    } else
      cout << -1 << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
