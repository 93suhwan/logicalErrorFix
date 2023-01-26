#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  int sum = 0;
  sum = (a / 2) + (b / 2) + (c / 2);
  if (sum >= m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
