#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  int pxor;
  if (a % 4 == 1)
    pxor = a - 1;
  else if (a % 4 == 2)
    pxor = 1;
  else if (a % 4 == 3)
    pxor = a;
  else
    pxor = 0;
  if (pxor == b)
    cout << a << "\n";
  else if ((pxor ^ b) != a)
    cout << a + 1 << "\n";
  else
    cout << a + 2 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
