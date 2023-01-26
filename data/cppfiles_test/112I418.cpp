#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  int minsum = 0, maxsum = 0;
  minsum = (a / 2) + (b / 2) + (c / 2);
  maxsum = a + b + c - 3;
  if (m >= minsum && m <= maxsum)
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
