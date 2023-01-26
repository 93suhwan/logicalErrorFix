#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
void solve() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  a /= 2, b /= 2, c /= 2;
  if (a + b + c >= m)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
