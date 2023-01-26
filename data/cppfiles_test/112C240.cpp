#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
void solve() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  if (m > a + b + c - 3 || m < 2 * max({a, b, c}) - a - b - c - 1)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
