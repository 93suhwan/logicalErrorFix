#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int s = a + 2 * b + 3 * c;
  if (s & 1)
    cout << 1 << '\n';
  else
    cout << 0 << '\n';
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
